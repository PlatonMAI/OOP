#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include <shared_mutex>

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
    int x, y;
    std::vector<std::shared_ptr<IFightObserver>> observers;
    std::mutex mtx;

protected:
    NpcType type;
    bool isDead = false;

public:
    NPC(NpcType t, int _x, int _y);

    NpcType get_type() const;

    void subscribe(const std::shared_ptr<IFightObserver>);
    void fight_notify(const std::shared_ptr<NPC> defender, bool win);
    bool is_close(const std::shared_ptr<NPC> &other) const;

    // Драка
    virtual bool accept(const std::shared_ptr<NPC> &attacker) = 0;
    virtual bool fight(const Outlaw &defender) const = 0;
    virtual bool fight(const Knight &defender) const = 0;
    virtual bool fight(const Elf &defender) const = 0;
    void death();
    bool isAlive() const;
    virtual int getDistanceFight() const = 0;

    // Движение
    std::pair<int, int> position() const;
    void move(int shift_x, int shift_y, int MAX_X, int MAX_Y);
    virtual int getDistanceMove() const = 0;

    virtual void print() = 0;
    virtual void print(std::ostream &os) = 0;
    virtual void save(std::ostream &os);
    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};