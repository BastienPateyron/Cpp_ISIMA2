#pragma once
#include "B.hpp"

class B; // Forward , declaration anticipee

class A
{
  private:
    int i;
  
  public:
    void send(B *);
    void exec(int);
};