#pragma once

#include <iostream>

#include "../../interfaces/interface-console.hpp"
#include "../../interfaces/interface-cpu.hpp"
#include "../../interfaces/interface-display.hpp"
#include "../../interfaces/interface-tester-cpu-display.hpp"

#include "../../utilities/utilities.hpp"

#include "../display/display.hpp"
#include "../console/console.hpp"
#include "../cpu/cpu.hpp"

class Tester : public InterfaceTester
{
public:
  virtual void sum();
  virtual void sub();
  virtual void mult();
  virtual void div();
};
