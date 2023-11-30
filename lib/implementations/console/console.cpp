#include "console.hpp"
#include <iostream>
#include <cstdlib>
#include <cwchar>

Console::Console()
{
  this->console = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Console::setPixel(int x, int y, ConsolePixelStyles style)
{
  if (this->console == INVALID_HANDLE_VALUE)
  {
    std::cerr << "Erro ao obter o identificador do console\n";
    return;
  }

  COORD position;
  position.X = x; // Coluna
  position.Y = y; // Linha

  if (!SetConsoleCursorPosition(this->console, position))
  {
    std::cerr << "Erro ao definir a posição do cursor\n";
    return;
  }

  char pixel = style == FILL ? 219 : style == EMPTY ? ' '
                                                    : 'x';

  std::cout << pixel;
}

void Console::clearScreen()
{
  system("cls");
}