#include <mutex>
#include <queue>
#include <memory>
#include <shared_mutex>
#include <optional>
#include <thread>

#include <npc.h>
#include <print.h>

using namespace std::chrono_literals;

struct FightEvent {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager {
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager& get();

    void add_event(FightEvent &&event);

    void operator()();

    bool isWork();
};