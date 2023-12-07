#include "cpu.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Memory convertFloatToMemory(float number)
{
  Memory retorno = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      0,
      0,
      number < 0};

  number *= number < 0 ? -1 : 1;

  int integer = (int)number;
  float frac = number - integer;
  int dot = 0;

  int fracInt = 0;
  for (int i = 0; i < 6 && frac != 0; i++)
  {
    frac *= 10;
    fracInt = (fracInt * 10) + (int)frac;
    if (frac > 0)
      dot++;
    frac -= (int)frac;
  }

  for (int i = 0; i < dot; i++)
  {
    int digito = fracInt % 10;
    retorno.v[MAX_MEMORY - 1 - i] = digito;
    fracInt /= 10;
  }

  for (int i = dot; i < MAX_MEMORY; i++)
  {
    int digito = integer % 10;
    retorno.v[MAX_MEMORY - 1 - i] = digito;
    integer /= 10;
  }

  retorno.dot = dot;

  return retorno;
}

void Cpu::add(unsigned int digit)
{
  for (int i = 0; i < MAX_MEMORY - 1; i++)
    this->value.v[i] = this->value.v[i + 1];

  this->value.v[MAX_MEMORY - 1] = digit;
  this->value.n += this->value.n < MAX_MEMORY;
}

void Cpu::addDot()
{
  if (this->value.dot == 0)
    this->value.dot = this->value.n;
}

void Cpu::removeLastDigit()
{
  if (this->value.n > 0)
  {
    this->value.n--;
    if (this->value.dot > this->value.n)
      this->value.dot = this->value.n;
  }
}

void Cpu::clearAll()
{
  this->value.n = 0;
  this->value.dot = 0;
  for (int i = 0; i < MAX_MEMORY; i++)
    this->value.v[i] = 0;

  this->result = 0;
}

void Cpu::clearValue()
{
  this->value.n = 0;
  this->value.dot = 0;
  for (int i = 0; i < MAX_MEMORY; i++)
    this->value.v[i] = 0;
}

void Cpu::setOperation(Operation operation)
{
  this->operation = operation;
  if (this->value.n > 0)
  {
    this->doOperation();
    this->clearValue();
  }
}

void Cpu::doOperation()
{
  float value = 0;

  for (int i = 0; i < MAX_MEMORY; i++)
    value = (value * 10) + (float)this->value.v[i];

  if (this->value.dot != 0)
    value /= pow(10, this->value.n - this->value.dot);

  switch (this->operation)
  {
  case OP_SUM:
    this->result += value;
    break;
  case OP_SUB:
    this->result -= value;
    break;
  case OP_DIVISION:
    this->result /= value;
    break;
  case OP_MULTIPLICATION:
    this->result *= value;
    break;
  case OP_PERCENTAGE:
    break;
  case OP_SQUARE_ROOT:
    break;
  default:
    break;
  }
}

Memory Cpu::getValue()
{
  return this->value;
}

Memory Cpu::getResult()
{
  return convertFloatToMemory(this->result);
}