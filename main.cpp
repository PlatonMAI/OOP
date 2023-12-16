#include "npc.h"
#include "outlaw.h"
#include "knight.h"
#include "elf.h"
#include "serialization.h"
#include "text_observer.h"
#include "file_observer.h"
#include "fight_manager.h"
#include "print.h"

#include <algorithm>
#include <sstream>
#include <future>

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;
std::mutex print_mutex;

// print to screen
ostream &operator<<(ostream &os, const vector_NPC &array) {
    for (auto ptr : array)
        ptr->print();
    return os;
}

int create_process() {
    pid_t pid = fork();
    if (-1 == pid) {
        perror("fork");
        exit(-1);
    }
    return pid;
}

int main() {
    vector_NPC array;
    Factory factory;
    shared_ptr<IFightObserver> tobserver = make_shared<TextObserver>();
    shared_ptr<IFightObserver> fobserver = make_shared<FileObserver>();
    vector< shared_ptr<IFightObserver> > observers{tobserver, fobserver};

    const int MAX_X{100};
    const int MAX_Y{100};
    const int MOBS{50};

    srand(42);
    for (size_t i = 0; i < MOBS; ++i)
        array.push_back( factory.factory(NpcType(rand() % 3), rand() % 100, rand() % 100, observers) );

    cout << "Генерация:" << endl << array << endl;

    std::thread fight_thread(std::ref(FightManager::get()));

    std::thread move_thread([&array, MAX_X, MAX_Y]() {
        while (true) {
            // move phase
            for (std::shared_ptr<NPC> npc : array) {
                    if (npc->isAlive()) {
                        int distance_move = npc->getDistanceMove();
                        int shift_x = std::rand() % distance_move - distance_move / 2;
                        int shift_y = std::rand() % distance_move - distance_move / 2;
                        npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                    }
            }
            print(&print_mutex) << "Я move_thread, я передвинул бойцов" << endl;

            // lets fight
            for (std::shared_ptr<NPC> attacker : array)
                for (std::shared_ptr<NPC> defender : array)
                        if (attacker != defender && attacker->isAlive() && defender->isAlive() && attacker->is_close(defender))
                            FightManager::get().add_event({attacker, defender});

            print(&print_mutex) << "Я move_thread, я провел сражение" << endl;

            std::this_thread::sleep_for(500ms);
        }
    });

    auto begin = std::chrono::high_resolution_clock::now();



    // Начинается пиздец

    int pipe_fd[2];
    pipe(pipe_fd);

    pid_t process_id = create_process();
    if (process_id == 0) {
        close(pipe_fd[1]);
        dup2(pipe_fd[0], 0);
        execl("main.py", "", NULL);
        perror("exec");
        exit(-1);
    }
    close(pipe_fd[0]);

    char bufer[2 + MOBS * 10];
    bufer[0] = '1';
    bufer[1] = '\n';
    while (true) {
        int cur_pos = 2;
        for (std::shared_ptr<NPC> npc : array) {
            NpcType type = npc->get_type();
            auto [x, y] = npc->position();
            bool isAlive = npc->isAlive();

            stringstream ss;
            ss << type << " " << x << " " << y << " " << isAlive << "\n";
            string s = ss.str();
            const char* c = s.c_str();
            strcpy(bufer + cur_pos, c);
            cur_pos += strlen(c);
        }
        bufer[cur_pos] = 0;

        write(pipe_fd[1], bufer, sizeof(char) * strlen(bufer));

        print(&print_mutex) << "Я главный процесс, отправил новую партию на отрисовку" << endl;

        auto end = std::chrono::high_resolution_clock::now();
        auto seconds = std::chrono::duration_cast <std::chrono::seconds>( end - begin ).count();

        if (seconds >= 30) {
            print(&print_mutex) << "Останавливаю поток движения" << endl;
            move_thread.detach();

            while(FightManager::get().isWork()) {
                print(&print_mutex) << "Бурбздум..." << endl;
                std::this_thread::sleep_for(100ms);
            }
            print(&print_mutex) << "Останавливаю поток драки" << endl;
            fight_thread.detach();

            print(&print_mutex) << "Отправляю код завершения процессу отрисовки" << endl;
            write(pipe_fd[1], "eof\n", sizeof(char) * 4);

            print(&print_mutex) << "...и убиваю его" << endl;
            kill(process_id, SIGTERM);

            print(&print_mutex) << "Список выживших бойцов:" << endl;
            for (std::shared_ptr<NPC> npc : array) {
                if (npc->isAlive())
                    npc->print();
            }

            print(&print_mutex) << "Останавливаюсь сам..." << endl;
            break;
        }

        std::this_thread::sleep_for(500ms);
    };

    return 0;
}