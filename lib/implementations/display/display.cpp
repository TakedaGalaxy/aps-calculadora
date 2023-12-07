#include "display.hpp"
#include <stdio.h>

Display::Display(InterfaceConsole *interfaceConsole)
{
  this->console = interfaceConsole;
}

void Display::on()
{
  this->reset();
  if (!this->displayOn)
  {
    console->clearScreen();
    this->displayOn = true;
  }
}

void Display::drawDigit(int x, int y, const bool digit[15])
{
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 3; j++)
      this->console->setPixel(x + j, y + i, digit[j + (i * 3)] ? FILL : EMPTY);
}

void Display::off()
{
  this->reset();
  if (this->displayOn)
  {
    console->clearScreen();
    this->displayOn = false;
  }
}
void Display::reset()
{
  this->console->clearScreen();
  this->clear();
  this->clearResult();
  this->setOperation(NONE);
}
void Display::clear()
{
  for (int i = 0; i < this->MAX_DIGITS; i++)
    this->valueBuffer[i] = SPACE;
}

void Display::addOnResult(Sysmbol newSysmbol)
{
  for (int i = 0; i < this->MAX_DIGITS - 1; i++)
    this->resultBuffer[i] = this->resultBuffer[i + 1];

  this->resultBuffer[this->MAX_DIGITS - 1] = newSysmbol;
}

void Display::setOnResult(Sysmbol *v, int n)
{
  for (int i = 0; i < this->MAX_DIGITS && i < n; i++)
    this->resultBuffer[i] = v[i];
}

void Display::clearResult()
{
  for (int i = 0; i < this->MAX_DIGITS; i++)
    this->resultBuffer[i] = SPACE;
}

void Display::add(Sysmbol newSysmbol)
{
  for (int i = 0; i < this->MAX_DIGITS - 1; i++)
    this->valueBuffer[i] = this->valueBuffer[i + 1];

  this->valueBuffer[this->MAX_DIGITS - 1] = newSysmbol;
}

void Display::set(Sysmbol *v, int n)
{
  for (int i = 0; i < this->MAX_DIGITS && i < n; i++)
    this->valueBuffer[i] = v[i];
}

void Display::setOperation(OperationSysmbol operation)
{
  this->operationBuffer = operation;
}

void Display::setOn(IndicatorSysmbol)
{
}
void Display::setOff(IndicatorSysmbol)
{
}

void Display::render()
{
  console->clearScreen();

  //
  for (int i = 0; i < this->MAX_DIGITS; i++)
    this->drawDigit((i * 3) + i, 0, SysmboyShape[this->resultBuffer[i]]);

  //
  this->drawDigit(this->MAX_DIGITS * 3 + this->MAX_DIGITS + 1, 0, OperationSysmboyShape[this->operationBuffer]);

  //
  for (int i = 0; i < this->MAX_DIGITS * 3 + this->MAX_DIGITS - 1; i++)
    this->console->setPixel(i, 5, DOT);

  //
  for (int i = 0; i < this->MAX_DIGITS; i++)
    this->drawDigit((i * 3) + i, 6, SysmboyShape[this->valueBuffer[i]]);
}