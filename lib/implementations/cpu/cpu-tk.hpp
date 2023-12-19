#pragma once

#include "../../interfaces/calculator.hpp"

class CpuTK: public Cpu{
  private:
    Display* display;

  public:
    Display* getDisplay();
    void setDisplay(Display*);

    void receiveDigit(Digit);
    void receiveOperator(Operator);
    void receiveControl(Control);
};