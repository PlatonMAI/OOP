#pragma once
#include "npc.h"

class Elf : public NPC {
private:
    const static inline std::string name = "elf";
    const static inline int distance_move = 10;
    const static inline int distance_fight = 50;

public:
    Elf(int x, int y);
    
    // Драка
    bool accept(const std::shared_ptr<NPC> &attacker) override;
    virtual bool fight(const Outlaw &defender) const override;
    virtual bool fight(const Knight &defender) const override;
    virtual bool fight(const Elf &defender) const override;
    int getDistanceFight() const override;

    // Движение
    int getDistanceMove() const override;

    void print() override;
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    friend std::ostream &operator<<(std::ostream &os, Elf &elf);
};