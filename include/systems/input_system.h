#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include "system.h"

class InputSystem : public System {
public:
    void update(std::vector<Entity>& entities) override;
private:
    void movePlayer(std::vector<Entity>& entities);
};

#endif // INPUT_SYSTEM_H
