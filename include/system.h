#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "entity.h"

class System {
public:
    virtual void update(std::vector<Entity>& entities) = 0;
};

#endif // SYSTEM_H
