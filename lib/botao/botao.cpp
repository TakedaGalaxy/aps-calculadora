#include "./botao.hpp"
#include "Windows.h"

Botao::Botao(IndentificadorBotao identificador)
    : estado({false, false}), identificador(identificador)
{
}

Botao::~Botao()
{
}

bool Botao::botaoPrecionado()
{
  return GetAsyncKeyState(this->identificador);
}

bool Botao::qualEstadoBotao()
{
  bool estadoAtual = this->botaoPrecionado();

  if (this->estado.lido)
  {
    if (this->estado.precionado != estadoAtual)
      this->estado = {false, false};

    return false;
  }

  if (estadoAtual)
  {
    this->estado = {true, true};
    return true;
  }

  return false;
}