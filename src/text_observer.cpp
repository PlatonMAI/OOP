#include <text_observer.h>

void TextObserver::on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) {
    if (!win)
        return;

    std::cout << std::endl << "Murder --------" << std::endl;
    attacker->print();
    defender->print();
    std::cout << std::endl;
}