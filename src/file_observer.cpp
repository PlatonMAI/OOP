#include <file_observer.h>

FileObserver::FileObserver() {
    file.open(filename);
};
FileObserver::~FileObserver() {
    file.close();
};

void FileObserver::on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) {
    if (!win)
        return;

    file << "Murder --------\n";
    attacker->print(file);
    defender->print(file);
    file << std::endl;
}