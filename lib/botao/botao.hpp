#ifndef BOTAO_HPP
#define BOTAO_HPP

enum IndentificadorBotao
{
  VAZIO = 0,
  ZERO = '0',
  UM,
  DOIS,
  TRES,
  QUATRO,
  CINCO,
  SEIS,
  SETE,
  OITO,
  NOVE,
  MULTIPLICACAO = '*',
  DIVISAO = '/',
  SUBTRACAO = '-',
  ADICAO = '+',
  IGUAL = '=',
  LIMPAR = 'c'
};

typedef struct
{
  bool precionado;
  bool lido;
} EstatusBotao;

class Botao
{
private:
  IndentificadorBotao identificador;
  EstatusBotao estado;

  bool botaoPrecionado();

public:
  bool qualEstadoBotao();

  Botao(IndentificadorBotao identificador);
  ~Botao();
};

#endif