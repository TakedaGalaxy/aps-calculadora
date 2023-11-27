#include "CpuLucio.hpp"

Display *CpuLucio::getDisplay() { return this->display; }
void CpuLucio::setDisplay(Display *display) { this->display = display; }

void CpuLucio::receiveDigit(Digit digit) {
  if(this->display!=nullptr) this->display->add(digit);
    /* TODO */
}
void CpuLucio::receiveOperator(Operator) { /* TODO */
}
void CpuLucio::receiveControl(Control) { /* TODO */
}
