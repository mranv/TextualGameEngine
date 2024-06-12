#include <iostream>
#include "component_manager.h"
#include "components/position_component.h"
#include "components/name_component.h"
#include "systems/render_system.h"


void RenderSystem::update(std::vector<Entity>& entities) {
    for (auto& entity : entities) {
        PositionComponent* position = static_cast<PositionComponent*>(componentManager->getComponent(entity.getId(), "Position"));
        NameComponent* name = static_cast<NameComponent*>(componentManager->getComponent(entity.getId(), "Name"));
        if (position && name) {
            std::cout << name->name << " is at (" << position->x << ", " << position->y << ")" << std::endl;
        }
    }
}
