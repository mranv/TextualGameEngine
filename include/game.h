#ifndef GAME_H
#define GAME_H

#include <memory>
#include "entity_manager.h"
#include "component_manager.h"
#include "system_manager.h"

class Game {
public:
    void initialize();
    void run();
private:
    std::unique_ptr<EntityManager> entityManager;
    std::unique_ptr<ComponentManager> componentManager;
    std::unique_ptr<SystemManager> systemManager;
};

#endif // GAME_H
