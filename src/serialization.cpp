#include <serialization.h>

void save(const vector_NPC &array, const std::string &filename) {
    std::ofstream fs(filename, std::ios_base::out);
    fs << array.size() << std::endl;
    for (auto ptr : array)
        ptr->save(fs);
    fs.flush();
    fs.close();
}

vector_NPC load(const std::string &filename) {
    Factory factory;
    vector_NPC result;
    std::ifstream is(filename);

    int count;
    is >> count;
    int type;
    int x, y;
    for (int i = 0; i < count; ++i) {
        is >> type >> x >> y;

        result.push_back(factory.factory(static_cast<NpcType>(type), x, y));
    }
    is.close();
    
    return result;
}

vector_NPC load(const std::string &filename, std::vector< std::shared_ptr<IFightObserver> > observers) {
    vector_NPC result = load(filename);

    for (auto npc : result) {
        for (auto observer : observers) {
            npc->subscribe(observer);
        }
    }
    
    return result;
}