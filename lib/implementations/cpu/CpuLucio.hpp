#pragma once

#include "../../interfaces/CalculatorInterfaces.hpp"

class CpuLucio: public Cpu{
  private:
    Display* display;

  public:
    Display* getDisplay();
    void setDisplay(Display*);

    void receiveDigit(Digit);
    void receiveOperator(Operator);
    void receiveControl(Control);
};