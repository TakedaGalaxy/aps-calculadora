#pragma once

#include "../../interfaces/interface-cpu.hpp"

class Cpu : public InterfaceCpu
{
private:
  Memory value = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      0,
      0,
      0};

  float result = 0;

  unsigned int intexDot = 0;

  Operation operation = OP_NONE;

public:
  virtual void add(unsigned int digit);
  virtual void addDot();
  virtual void removeLastDigit();
  virtual void clearAll();
  virtual void clearValue();
  virtual void setOperation(Operation operation);
  virtual void doOperation();
  virtual Memory getValue();
  virtual Memory getResult();
};