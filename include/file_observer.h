#include <Ifight_observer.h>
#include <npc.h>

#include <fstream>

class FileObserver : public IFightObserver {
private:
    const static inline std::string filename = "log.txt";
    std::ofstream file;

public:
    FileObserver();
    ~FileObserver();

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override;
};