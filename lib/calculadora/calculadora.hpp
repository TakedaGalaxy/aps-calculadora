#ifndef CALCULADORA_HPP  
#define CALCULADORA_HPP

#include "../tela/tela.hpp"
#include "../cpu/cpu.hpp"
#include "../teclado/teclado.hpp"

class Calculadora{
  private:
    Tela *tela;
    Cpu *cpu;
    Teclado *teclado;
  
  public:
    void logica();
    Calculadora();
    ~Calculadora();
};

#endif  