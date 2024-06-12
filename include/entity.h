#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <unordered_map>
#include "component.h"

class Entity {
public:
    Entity(const std::string& name, int id) : name(name), id(id) {}
    const std::string& getName() const { return name; }
    int getId() const { return id; }
private:
    std::string name;
    int id;
};

#endif // ENTITY_H
