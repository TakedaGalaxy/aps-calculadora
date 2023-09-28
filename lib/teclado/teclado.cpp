#include "./teclado.hpp"

Teclado::Teclado(IndentificadorBotao *identificadores, unsigned int quantidade)
    : botoes(new ControleBotao[quantidadeBotoes]), quantidadeBotoes(quantidade)
{
  for (int i = 0; i < quantidade; i++)
  {
    this->botoes[i].identificador = identificadores[i];
    this->botoes[i].botao = new Botao(identificadores[i]);
  }
}

Teclado::~Teclado()
{
}

void Teclado::associarEvento(IndentificadorBotao botao, void (*evento)(void))
{
  if (evento != nullptr)
    for (int i = 0; i < this->quantidadeBotoes; i++)
      if (this->botoes[i].identificador == botao)
        this->botoes[i].evento = evento;
}

void Teclado::executaOcorrenciaEventos()
{
  for (int i = 0; i < this->quantidadeBotoes; i++)
    if (this->botoes[i].evento != nullptr)
      if (this->botoes[i].botao->qualEstadoBotao())
        this->botoes[i].evento();
}