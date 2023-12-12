#include <Ifight_observer.h>
#include <npc.h>

class TextObserver : public IFightObserver {
// private:
//     TextObserver(){};

public:
    // static std::shared_ptr<IFightObserver> get()
    // {
    //     static TextObserver instance;
    //     return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    // }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override;
};