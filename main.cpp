#include "main.hpp"

int main()
{

  InterfaceConsole *console = new Console();

  console->clearScreen();

  for (int x = 0; x < 10; x++)
    for (int y = 0; y < 10; y++)
      console->setPixel(x, y, FILL);

  return 0;
}