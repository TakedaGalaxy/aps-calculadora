#include "cpu-tk.hpp"
#include "iostream"

Display *CpuTK::getDisplay() { return this->display; }
void CpuTK::setDisplay(Display *display) { this->display = display; }

void CpuTK::receiveDigit(Digit digit)
{
  if (this->display != nullptr)
    this->display->add(digit);
  /* TODO */
}
void CpuTK::receiveOperator(Operator)
{ /* TODO */
}
void CpuTK::receiveControl(Control)

{ /* TODO */
}
