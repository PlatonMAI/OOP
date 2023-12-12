#include "npc.h"
#include "outlaw.h"
#include "knight.h"
#include "elf.h"
#include "serialization.h"

#include <algorithm>

using namespace std;

// print to screen
std::ostream &operator<<(std::ostream &os, const vector_NPC &array) {
    for (auto ptr : array)
        ptr->print();
    return os;
}

vector_NPC fight(const vector_NPC &array, size_t distance) {
    vector_NPC dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance))) {\
                bool success = defender->accept(attacker);

                if (success)
                    dead_list.push_back(defender);
            }

    return dead_list;
}

int main()
{
    vector_NPC array; // монстры
    Factory factory;

    // Гененрируем начальное распределение монстров
    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 10; ++i)
        array.push_back(factory.factory(NpcType(std::rand() % 3), std::rand() % 100, std::rand() % 100));
    
    std::cout << "Saving ..." << std::endl;
    save(array, "npc.txt");

    std::cout << "Loading ..." << std::endl;
    array = load("npc.txt");

    std::cout << "Генерация:" << std::endl << array << std::endl;

    std::cout << "Fighting ..." << std::endl;
    int i = 0;
    for (size_t distance = 20; (distance <= 100) && !array.empty(); distance += 10) {
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list)
            array.erase( find(array.begin(), array.end(), d) );
        
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl << std::endl;

        std::string filename = "txt/npc";
        filename.push_back(++i + '0');
        save(array, filename);
    }

    std::cout << "Survivors:" << std::endl << array;



    // Outlaw a(10, 20);
    // Elf b(10, 21);

    // shared_ptr<NPC> poutlaw = make_shared<Outlaw>(10, 20);

    // cout << b.accept(poutlaw) << endl;

    return 0;
}