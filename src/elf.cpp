#include "outlaw.h"
#include "knight.h"
#include "elf.h"

Elf::Elf(int x, int y) : NPC(ElfType, x, y) {}

bool Elf::accept(const std::shared_ptr<NPC> &attacker) {
    if (isDeath)
        return false;
    
    bool success = attacker->fight(*this);
    if (success)
        death();
    return success;
}
bool Elf::fight(const Outlaw &defender) const {
    return false;
};
bool Elf::fight(const Knight &defender) const {
    return true;
};
bool Elf::fight(const Elf &defender) const {
    return false;
};

void Elf::print() {
    print(std::cout);
}
void Elf::print(std::ostream &os) {
    os << *this;
}
void Elf::save(std::ostream &os) {
    os << ElfType << " ";
    NPC::save(os);
}
std::ostream &operator<<(std::ostream &os, Elf &elf)
{
    os << Elf::name << " " << *static_cast<NPC*>(&elf) << std::endl;
    return os;
}