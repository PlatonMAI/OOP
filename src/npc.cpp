#include "npc.h"

NPC::NPC(NpcType t, int _x, int _y) : type(t), x(_x), y(_y) {}

NpcType NPC::get_type() const {
    return this->type;
}

void NPC::subscribe(const std::shared_ptr<IFightObserver> observer) {
    observers.push_back(observer);
}
void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win) {
    for (auto &observer : observers) {
        observer->on_fight(shared_from_this(), defender, win);
    }
}
bool NPC::is_close(const std::shared_ptr<NPC> &other) const {
    return std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(this->getDistanceFight(), 2);
}
void NPC::death() {
    isDead = true;
}
bool NPC::isAlive() const {
    return !isDead;
}

std::pair<int, int> NPC::position() const {
    return {x, y};
}
void NPC::move(int shift_x, int shift_y, int MAX_X, int MAX_Y) {
    x = (x + shift_x + MAX_X) % MAX_X;
    y = (y + shift_y + MAX_Y) % MAX_Y;
}

void NPC::save(std::ostream &os) {
    os << x << " " << y << std::endl;
}
std::ostream &operator<<(std::ostream &os, NPC &npc) {
    os << "{x:" << npc.x << ", y:" << npc.y << "}";
    return os;
}