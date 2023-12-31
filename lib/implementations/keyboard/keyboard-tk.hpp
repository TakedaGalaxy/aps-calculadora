#pragma once

#include "../../interfaces/calculator.hpp"

class KeyboardTK : public Keyboard
{
  static const char MAX_KEYS = 101;

  Key *keys[MAX_KEYS];
  char keysCount = 0;
  Cpu *cpu;

public:
  void addKey(Key *);
  void removeKey(Key *);
  Key *findKey(Symbol);
  void setCpu(Cpu *);
  Cpu *getCpu();
};