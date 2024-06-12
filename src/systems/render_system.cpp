#include "render_system.h"
#include <iostream>
#include "component_manager.h"
#include "components/position_component.h"
#include "components/name_component.h"

void RenderSystem::update(std::vector<Entity>& entities) {
    for (auto& entity : entities) {
        PositionComponent* position = dynamic_cast<PositionComponent*>(componentManager->getComponent(entity.getId(), "Position"));
        NameComponent* name = dynamic_cast<NameComponent*>(componentManager->getComponent(entity.getId(), "Name"));
        if (position && name) {
            std::cout << name->name << " is at (" << position->x << ", " << position->y << ")" << std::endl;
        }
    }
}
