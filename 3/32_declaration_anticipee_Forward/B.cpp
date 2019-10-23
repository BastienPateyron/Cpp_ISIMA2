#include "B.hpp"

void B::send(A * a)
{
  a->exec(10);
}

void B::exec(int x)
{
  this->j += x;
}