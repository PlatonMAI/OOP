#include <factory.h>

std::shared_ptr<NPC> Factory::factory(NpcType type, int x, int y) {
    std::shared_ptr<NPC> result;
    switch (type) {
    case OutlawType:
        result = std::make_shared<Outlaw>(x, y);
        break;
    case KnightType:
        result = std::make_shared<Knight>(x, y);
        break;
    case ElfType:
        result = std::make_shared<Elf>(x, y);
        break;
    default:
        throw new std::invalid_argument("Требуемый тип не существует!");
        break;
    }

    return result;
}

std::shared_ptr<NPC> Factory::factory(NpcType type, int x, int y, std::vector< std::shared_ptr<IFightObserver> > observers) {
    std::shared_ptr<NPC> result = factory(type, x, y);

    for (auto observer : observers)
        result->subscribe(observer);

    return result;
}