#pragma once

enum ConsolePixelStyles
{
  FILL,
  EMPTY,
  DOT
};

class InterfaceConsole
{
public:
  virtual void setPixel(int x, int y, ConsolePixelStyles style) = 0;
  virtual void clearScreen() = 0;
};