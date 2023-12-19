#include "cpu-tk.hpp"
#include "iostream"

Display *CpuTK::getDisplay() { return this->display; }
void CpuTK::setDisplay(Display *display) { this->display = display; }

void CpuTK::receiveDigit(Digit digit)
{
  if (this->display != nullptr)
    this->display->add(digit);
}
void CpuTK::receiveOperator(Operator op)
{
  switch (op)
  {
  case SUM:
    break;
  case SUBTRACTION:
    break;
  case DIVISION:
    break;
  case MULTIPLICATION:
    break;
  case PERCENTAGE:
    break;
  case SQUARE_ROOT:
    break;
  default:
    throw("Operator not found!");
    break;
  }
}

void CpuTK::receiveControl(Control control)
{
  switch (control)
  {
  case ON:
    break;
  case OFF:
    break;
  case CLEAR_ERROR:
    break;
  case MEMORY_READ_CLEAR:
    break;
  case MEMORY_SUM:
    break;
  case MEMORY_SUBTRACTION:
    break;
  case EQUAL:
    break;
  case DECIMAL_SEPARATOR:
    break;

  default:
    throw("Control not found!");
    break;
  }
}
