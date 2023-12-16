#include <Ifight_observer.h>
#include <npc.h>
// #include <print.h>

class TextObserver : public IFightObserver {
// private:
    // std::mutex* print_mutex;

public:
    // TextObserver(std::mutex* _mutex) : print_mutex(_mutex){};
    // static std::shared_ptr<IFightObserver> get()
    // {
    //     static TextObserver instance;
    //     return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    // }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override;
};