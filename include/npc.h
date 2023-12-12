#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>

#include <Ifight_observer.h>

class Outlaw;
class Knight;
class Elf;

enum NpcType {
    OutlawType,
    KnightType,
    ElfType,
};

class IFightObserver;

class NPC : public std::enable_shared_from_this<NPC> {
private:
    NpcType type;
    int x, y;
    std::vector<std::shared_ptr<IFightObserver>> observers;

public:
    NPC(NpcType t, int _x, int _y);

    void subscribe(const std::shared_ptr<IFightObserver>);
    void fight_notify(const std::shared_ptr<NPC> defender, bool win);
    bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    virtual bool accept(const std::shared_ptr<NPC> &attacker) const = 0;
    virtual bool fight(const Outlaw &defender) const = 0;
    virtual bool fight(const Knight &defender) const = 0;
    virtual bool fight(const Elf &defender) const = 0;

    virtual void print() = 0;
    virtual void print(std::ostream &os) = 0;
    virtual void save(std::ostream &os);
    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};