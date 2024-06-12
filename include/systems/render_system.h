#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "system.h"
#include "systems/render_system.h"


class RenderSystem : public System {
public:
    void update(std::vector<Entity>& entities) override;
};

#endif // RENDER_SYSTEM_H
