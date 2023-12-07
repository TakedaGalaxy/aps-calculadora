#include "main.hpp"

int main()
{

  InterfaceConsole *console = new Console();

  InterfaceDisplay *display = new Display(console);

  display->on();

  display->addOnResult(ONE);
  display->addOnResult(TWO);
  display->addOnResult(FOUR);

  display->add(FOUR);
  display->add(TWO);
  display->add(ONE);

  display->render();

  return 0;
}