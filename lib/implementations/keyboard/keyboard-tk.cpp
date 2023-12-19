#include <string.h>
#include "keyboard-tk.hpp"

void KeyboardTK::addKey(Key *key)
{
  for (int i = 0; i < this->keysCount; i++)
    if (!strcmp(this->keys[i]->getSymbol(), key->getSymbol()))
      throw("Repeated key!");

  if (this->keysCount >= this->MAX_KEYS)
    throw("Key limit reached!");

  this->keys[this->keysCount++] = key;
  key->setKeyboard(this);
}

void KeyboardTK::removeKey(Key *key)
{
  unsigned int i;
  for (i = 0; i < this->keysCount; i++)
    if (!strcmp(this->keys[i]->getSymbol(), key->getSymbol()))
      break;

  if (i == this->keysCount)
    throw("key does not exist!");

  this->keys[i]->setKeyboard(nullptr);

  for (; i < this->keysCount - 1; i++)
    this->keys[i] = this->keys[i + 1];

  this->keys[i] = nullptr;
}

Key *KeyboardTK::findKey(Symbol symbol)
{
  for (int i = 0; i < this->keysCount; i++)
    if (!strcmp(this->keys[i]->getSymbol(), symbol))
      return this->keys[i];

  throw("Key not found!");
}

void KeyboardTK::setCpu(Cpu *cpu)
{
  this->cpu = cpu;
}

Cpu *KeyboardTK::getCpu()
{
  return this->cpu;
}