#ifndef TECLADO_HPP
#define TECLADO_HPP

#include "../botao/botao.hpp"

struct controleBotao
{
  IndentificadorBotao identificador;
  Botao *botao;
  void (*evento)(void);

  controleBotao() : identificador(VAZIO), botao(nullptr), evento(nullptr){};
};

typedef controleBotao ControleBotao;

class Teclado
{
private:
  int quantidadeBotoes;
  ControleBotao *botoes;

public:

  void associarEvento(IndentificadorBotao botao, void (*evento)(void));
  void executaOcorrenciaEventos();

  Teclado(IndentificadorBotao *identificadores, unsigned int quantidade);
  ~Teclado();
};

#endif