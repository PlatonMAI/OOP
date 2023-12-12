#include "npc.h"

NPC::NPC(NpcType t, int _x, int _y) : type(t), x(_x), y(_y) {}

void NPC::subscribe(const std::shared_ptr<IFightObserver> observer) {
   observers.push_back(observer);
}
void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win) {
    for (auto &observer : observers)
        observer->on_fight(shared_from_this(), defender, win);
}
bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const {
    // std::cout << "Я " << typeid(*this).name() << " " << this->x << " " << this->y << " считаю доступность для " << typeid(*other).name() << " " << other->x << " " << other->y << std::endl;

    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}
void NPC::death() {
    isDeath = true;
}

void NPC::save(std::ostream &os) {
    os << x << " " << y << std::endl;
}
std::ostream &operator<<(std::ostream &os, NPC &npc) {
    os << "{x:" << npc.x << ", y:" << npc.y << "}";
    return os;
}