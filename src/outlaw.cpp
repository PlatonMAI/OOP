#include "outlaw.h"
#include "knight.h"
#include "elf.h"

Outlaw::Outlaw(int x, int y) : NPC(OutlawType, x, y) {}

bool Outlaw::accept(const std::shared_ptr<NPC> &attacker) {
    if (isDead)
        return false;
    
    bool success = attacker->fight(*this);
    attacker->fight_notify(shared_from_this(), success);
    if (success)
        death();
    return success;
}
bool Outlaw::fight(const Outlaw &defender) const {
    // std::cout << "Дерусь с собой епт (это как)" << std::endl;
    return false;
};
bool Outlaw::fight(const Knight &defender) const {
    // std::cout << "Дерусь с рыцарем епт" << std::endl;
    return false;
};
bool Outlaw::fight(const Elf &defender) const {
    // std::cout << "Дерусь с эльфом епт" << std::endl;
    return true;
};
int Outlaw::getDistanceFight() const {
    return distance_fight;
}

int Outlaw::getDistanceMove() const {
    return distance_move;
}

void Outlaw::print() {
    print(std::cout);
}
void Outlaw::print(std::ostream &os) {
    os << *this;
}
void Outlaw::save(std::ostream &os) {
    os << OutlawType << " ";
    NPC::save(os);
}
std::ostream &operator<<(std::ostream &os, Outlaw &Outlaw)
{
    os << Outlaw::name << " " << *static_cast<NPC*>(&Outlaw) << std::endl;
    return os;
}