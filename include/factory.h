#include "outlaw.h"
#include "knight.h"
#include "elf.h"

#include <Ifight_observer.h>

class Factory {
public:
    std::shared_ptr<NPC> factory(NpcType type, int x, int y);
    std::shared_ptr<NPC> factory(NpcType type, int x, int y, std::vector< std::shared_ptr<IFightObserver> > observers);
};