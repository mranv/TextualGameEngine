#include "entity_manager.h"
#include <algorithm> 

int EntityManager::nextId = 0;

Entity& EntityManager::createEntity(const std::string& name) {
    Entity entity(name, nextId++);
    entities.emplace_back(entity);
    return entities.back();
}

void EntityManager::destroyEntity(int id) {
    entities.erase(std::remove_if(entities.begin(), entities.end(),
                  [id](const Entity& entity) { return entity.getId() == id; }),
                  entities.end());
}

Entity* EntityManager::getEntity(int id) {
    for (auto& entity : entities) {
        if (entity.getId() == id) {
            return &entity;
        }
    }
    return nullptr;
}
