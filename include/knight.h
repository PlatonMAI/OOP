#pragma once
#include "npc.h"

class Knight : public NPC {
private:
    const static inline std::string name = "knight";

public:
    Knight(int x, int y);

    bool accept(const std::shared_ptr<NPC> &attacker) override;
    virtual bool fight(const Outlaw &defender) const override;
    virtual bool fight(const Knight &defender) const override;
    virtual bool fight(const Elf &defender) const override;

    void print() override;
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};