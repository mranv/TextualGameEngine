#include "system_manager.h"

void SystemManager::addSystem(System* system) {
    systems.push_back(system);
}

void SystemManager::updateSystems() {
    for (auto& system : systems) {
        system->update(entities);
    }
}

void SystemManager::setEntities(const std::vector<Entity>& ents) {
    entities = ents;
}
