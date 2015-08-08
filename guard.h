#pragma once

#include "npc.h"

class Guard : public NPC
{
public:
    Guard();
    void update();
private:
  bool boost;
};
