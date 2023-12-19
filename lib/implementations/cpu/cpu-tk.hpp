#pragma once

#include "../../interfaces/calculator.hpp"

struct Memory_8
{
  char digits[8];
  unsigned short int i;
  short int iDecimalSeparator;
};

class CpuTK : public Cpu
{
private:
  Display *display;

  Memory_8 result = {{0}, 0, -1};
  Memory_8 preparation = {{0}, 0, -1};

public:
  Display *getDisplay();
  void setDisplay(Display *);

  void receiveDigit(Digit);
  void receiveOperator(Operator);
  void receiveControl(Control);
};