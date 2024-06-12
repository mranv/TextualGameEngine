

#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <vector>
#include "system.h"
#include "entity.h"

class SystemManager {
public:
    void addSystem(System* system);
    void updateSystems();
    void setEntities(const std::vector<Entity>& entities);
private:
    std::vector<System*> systems;
    std::vector<Entity> entities;
};

#endif // SYSTEM_MANAGER_H
