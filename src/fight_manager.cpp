#include <fight_manager.h>

FightManager& FightManager::get() {
    static FightManager instance;
    return instance;
}

void FightManager::add_event(FightEvent &&event) {
    std::lock_guard<std::shared_mutex> lock(mtx);
    events.push(event);
}

void FightManager::operator()() {
    while (true) {
        std::optional<FightEvent> event;

        {
            std::lock_guard<std::shared_mutex> lock(mtx);
            if (!events.empty()) {
                event = events.back();
                events.pop();
            }
        }

        if (event) { 
            if (event->attacker->isAlive() && event->defender->isAlive()) {
                event->defender->accept(event->attacker); // Где нужно вызывать смерть и толкать обсерверы - тут или в аксепте?
                // print(&print_mutex) << "Я fight_manager, я проверил, что оба бойца живи. Выиграл ли нападающий - " << event->defender->accept(event->attacker); // Где нужно вызывать смерть и толкать обсерверы - тут или в аксепте?
            }
        }
        // else {
        //     std::this_thread::sleep_for(10ms);
        // }
    }
}

bool FightManager::isWork() {
    return events.size();
}