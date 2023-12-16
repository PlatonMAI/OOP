#include "outlaw.h"
#include "knight.h"
#include "elf.h"

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}

bool Knight::accept(const std::shared_ptr<NPC> &attacker) {
    if (isDead)
        return false;
    
    bool success = attacker->fight(*this);
    attacker->fight_notify(shared_from_this(), success);
    if (success)
        death();
    return success;
}
bool Knight::fight(const Outlaw &defender) const {
    return true;
};
bool Knight::fight(const Knight &defender) const {
    return false;
};
bool Knight::fight(const Elf &defender) const {
    return false;
};
int Knight::getDistanceFight() const {
    return distance_fight;
}

int Knight::getDistanceMove() const {
    return distance_move;
}

void Knight::print() {
    print(std::cout);
}
void Knight::print(std::ostream &os) {
    os << *this;
}
void Knight::save(std::ostream &os) {
    os << KnightType << " ";
    NPC::save(os);
}
std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << Knight::name << " " << *static_cast<NPC*>(&knight) << std::endl;
    return os;
}