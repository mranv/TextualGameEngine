#include "component_manager.h"

void ComponentManager::addComponent(int entityId, Component* component) {
    components[entityId][component->getName()] = component;
}

void ComponentManager::removeComponent(int entityId, const std::string& componentName) {
    components[entityId].erase(componentName);
}

Component* ComponentManager::getComponent(int entityId, const std::string& componentName) {
    if (components.find(entityId) != components.end() &&
        components[entityId].find(componentName) != components[entityId].end()) {
        return components[entityId][componentName];
    }
    return nullptr;
}
