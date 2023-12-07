#pragma once

enum Operation
{
  OP_NONE,
  OP_SUM,
  OP_SUB,
  OP_DIVISION,
  OP_MULTIPLICATION,
  OP_PERCENTAGE,
  OP_SQUARE_ROOT
};

const unsigned int MAX_MEMORY = 16;

struct Memory
{
  unsigned int v[MAX_MEMORY];
  unsigned int n;
  unsigned int dot;
  bool negative;
};

class InterfaceCpu
{
public:
  virtual void add(unsigned int digit) = 0;
  virtual void addDot() = 0;
  virtual void removeLastDigit() = 0;
  virtual void clearAll() = 0;
  virtual void clearValue() = 0;
  virtual void setOperation(Operation) = 0;
  virtual void doOperation() = 0;
  virtual Memory getValue() = 0;
  virtual Memory getResult() = 0;
};