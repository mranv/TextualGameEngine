#include "input_system.h"
#include <iostream>
#include <string>
#include "entity_manager.h"
#include "component_manager.h"
#include "components/position_component.h"

void InputSystem::update(std::vector<Entity>& entities) {
    std::string command;
    std::cout << "Enter command: ";
    std::getline(std::cin, command);

    if (command == "quit") {
        exit(0);
    } else if (command == "move") {
        movePlayer(entities);
    }
}

void InputSystem::movePlayer(std::vector<Entity>& entities) {
    for (auto& entity : entities) {
        if (entity.getName() == "Player") {
            PositionComponent* position = dynamic_cast<PositionComponent*>(componentManager->getComponent(entity.getId(), "Position"));
            if (position) {
                position->x += 1;
                position->y += 1;
            }
        }
    }
}
