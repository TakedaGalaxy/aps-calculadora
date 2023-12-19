#include "key-tk.hpp"

/* KEY TK */

KeyTK::KeyTK(Symbol symbol) { this->symbol = symbol; }

Symbol KeyTK::getSymbol() { return this->symbol; }

void KeyTK::setKeyboard(Keyboard *keyboard) { this->keyboard = keyboard; }
Keyboard *KeyTK::getKeyboard() { return this->keyboard; }

/* END */

/* KEY DIGIT TK */

KeyDigitTK::KeyDigitTK(Symbol symbol, Digit digit) : KeyTK(symbol)
{
  this->digit = digit;
}

Digit KeyDigitTK::getDigit() { return this->digit; }

void KeyDigitTK::press()
{
  this->getKeyboard()->getCpu()->receiveDigit(this->digit);
}

/* END */

/* KEY OPERATOR TK */

KeyOperatorTK::KeyOperatorTK(Symbol symbol, Operator operator_) : KeyTK(symbol)
{
  this->operator_ = operator_;
}

Operator KeyOperatorTK::getOperator() { return this->operator_; }

void KeyOperatorTK::press()
{
  this->getKeyboard()->getCpu()->receiveOperator(this->operator_);
}

/* END */

/* KEY CONTROL TK */

KeyControlTK::KeyControlTK(Symbol symbol, Control control) : KeyTK(symbol)
{
  this->control = control;
}

Control KeyControlTK::getControl() { return this->control; }

void KeyControlTK::press()
{
  this->getKeyboard()->getCpu()->receiveControl(this->control);
}

/* END */
