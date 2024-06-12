#include "movement_system.h"
#include "component_manager.h"
#include "components/position_component.h"

void MovementSystem::update(std::vector<Entity>& entities) {
    for (auto& entity : entities) {
        PositionComponent* position = dynamic_cast<PositionComponent*>(componentManager->getComponent(entity.getId(), "Position"));
        if (position) {
            position->x += 1;  // Simple movement logic for demonstration
            position->y += 1;
        }
    }
}
