#include "guard.h"
#include <iostream>

Guard::Guard()
{
  this->boost = false;
}

void Guard::update()
{
  this->doMove();
}




