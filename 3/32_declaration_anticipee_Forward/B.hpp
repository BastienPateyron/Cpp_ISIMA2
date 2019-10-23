#pragma once
#include "A.hpp"

class A; // Declaration anticipee

class B
{
  private:
    int j;

  public:
    void send(A *);
    void exec(int);
};