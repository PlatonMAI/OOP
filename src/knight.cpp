#include "outlaw.h"
#include "knight.h"
#include "elf.h"

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}

bool Knight::accept(const std::shared_ptr<NPC> &attacker) const {
    return attacker->fight(*this);
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