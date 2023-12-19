#pragma once

#include "../../interfaces/calculator.hpp"

class KeyTK : public virtual Key
{
  Keyboard *keyboard;
  Symbol symbol;

public:
  KeyTK(Symbol);

  Symbol getSymbol();

  void setKeyboard(Keyboard *);
  Keyboard *getKeyboard();
};

class KeyDigitTK : public KeyTK, public KeyDigit
{
  Digit digit;

public:
  KeyDigitTK(Symbol, Digit);

  Digit getDigit();

  void press();
};

class KeyOperatorTK : public KeyTK, public KeyOperator
{
  Operator operator_;

public:
  KeyOperatorTK(Symbol, Operator);

  Operator getOperator();

  void press();
};

class KeyControlTK : public KeyTK, public KeyControl
{
  Control control;

public:
  KeyControlTK(Symbol, Control);

  Control getControl();

  void press();
};