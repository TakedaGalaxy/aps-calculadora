#pragma once

#include <Windows.h>
#include "../../interfaces/interface-console.hpp"

class Console : public InterfaceConsole
{

private:
  HANDLE console;

public:
  Console();
  void setPixel(int x, int y, ConsolePixelStyles style);
  void clearScreen();
};