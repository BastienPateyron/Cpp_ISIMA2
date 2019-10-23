#include "A.hpp"

void A::send(B * b)
{
  b->exec(20);
}

void A::exec(int x)
{
  this->i += x;
}