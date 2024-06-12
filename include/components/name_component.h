#ifndef NAME_COMPONENT_H
#define NAME_COMPONENT_H

#include "component.h"
#include <string>

class NameComponent : public Component {
public:
    NameComponent(const std::string& name);
    std::string name;
};

#endif // NAME_COMPONENT_H
