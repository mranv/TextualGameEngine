#include "game.h"
#include "entity_manager.h"
#include "component_manager.h"
#include "system_manager.h"
#include "systems/input_system.h"
#include "systems/render_system.h"
#include "systems/movement_system.h"
#include "components/position_component.h"
#include "components/name_component.h"
#include "components/health_component.h"
#include <memory>

void Game::initialize() {
    // Initialize ECS Managers
    entityManager = std::make_unique<EntityManager>();
    componentManager = std::make_unique<ComponentManager>();
    systemManager = std::make_unique<SystemManager>();

    // Create Systems
    systemManager->addSystem(new InputSystem());
    systemManager->addSystem(new RenderSystem());
    systemManager->addSystem(new MovementSystem());

    // Create Entities
    Entity& player = entityManager->createEntity("Player");
    componentManager->addComponent(player.getId(), new NameComponent("Player"));
    componentManager->addComponent(player.getId(), new PositionComponent(0, 0));
    componentManager->addComponent(player.getId(), new HealthComponent(100));

    Entity& enemy = entityManager->createEntity("Enemy");
    componentManager->addComponent(enemy.getId(), new NameComponent("Goblin"));
    componentManager->addComponent(enemy.getId(), new PositionComponent(5, 5));
    componentManager->addComponent(enemy.getId(), new HealthComponent(50));

    // Set entities in SystemManager
    systemManager->setEntities(entityManager->getEntities());
}

void Game::run() {
    bool running = true;
    while (running) {
        systemManager->updateSystems();
    }
}
