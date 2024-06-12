#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "system.h"

class MovementSystem : public System {
public:
    void update(std::vector<Entity>& entities) override;
};

#endif // MOVEMENT_SYSTEM_H
