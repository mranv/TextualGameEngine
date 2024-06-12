#ifndef HEALTH_COMPONENT_H
#define HEALTH_COMPONENT_H

#include "component.h"

class HealthComponent : public Component {
public:
    HealthComponent(int health);
    int health;
};

#endif // HEALTH_COMPONENT_H
