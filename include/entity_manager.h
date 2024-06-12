#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>
#include <string>
#include "entity.h"

class EntityManager {
public:
    Entity& createEntity(const std::string& name);
    void destroyEntity(int id);
    Entity* getEntity(int id);
    const std::vector<Entity>& getEntities() const { return entities; }
private:
    std::vector<Entity> entities;
    static int nextId;
};

int EntityManager::nextId = 0;

#endif // ENTITY_MANAGER_H
