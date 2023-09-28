#include <iostream>
#include "./lib/calculadora/calculadora.hpp"

void printOK()
{
  std::cout << "OK" << std::endl;
}

int main(void)
{

  IndentificadorBotao listaBotoes[5] = {ZERO, UM, DOIS, TRES, QUATRO};

  Teclado teclado(listaBotoes, 5);

  teclado.associarEvento(ZERO, []()
                         { std::cout << "ZERO" << std::endl; });

  teclado.associarEvento(UM, []()
                         { std::cout << "UM" << std::endl; });

  teclado.associarEvento(DOIS, []()
                         { std::cout << "DOIS" << std::endl; });

  while (1)
  {
    teclado.executaOcorrenciaEventos();
  }
  return 0;
}