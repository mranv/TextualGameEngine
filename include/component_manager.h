#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H
#include "component.h"


#include <unordered_map>
#include <string>
#include "component.h"

class ComponentManager {
public:
    void addComponent(int entityId, Component* component);
    void removeComponent(int entityId, const std::string& componentName);
    Component* getComponent(int entityId, const std::string& componentName);
private:
    std::unordered_map<int, std::unordered_map<std::string, Component*>> components;
};

#endif // COMPONENT_MANAGER_H
