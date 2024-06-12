#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component {
public:
    Component(const std::string& name) : name(name) {}
    virtual ~Component() = default;
    const std::string& getName() const { return name; }
private:
    std::string name;
};

#endif // COMPONENT_H
