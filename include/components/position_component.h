#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include "component.h"

class PositionComponent : public Component {
public:
    PositionComponent(int x, int y);
    int x, y;
};

#endif // POSITION_COMPONENT_H
