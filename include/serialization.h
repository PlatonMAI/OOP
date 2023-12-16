#include <npc.h>
#include <factory.h>

#include <fstream>

using vector_NPC = std::vector< std::shared_ptr<NPC> >;

void save(const vector_NPC &array, const std::string &filename);

vector_NPC load(const std::string &filename);
vector_NPC load(const std::string &filename, std::vector< std::shared_ptr<IFightObserver> > observers);