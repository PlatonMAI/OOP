#pragma once

#include <iostream>
#include <memory>

class NPC;

class IFightObserver {
public:
    virtual void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) = 0;
};