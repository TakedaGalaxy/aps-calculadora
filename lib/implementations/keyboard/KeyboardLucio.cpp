#include "KeyboardLucio.hpp"


void KeyboardLucio::addKey(Key *key) {
  /* TODO No repeated keys!*/
  for(int i = 0; i < this->keysCount; i++)
    if(this->keys[i]==key) throw "Repeated key!";
  
  this->keys[this->keysCount++] = key;
  key->setKeyboard(this); /* Connect this keyboard with new key */    
}

void KeyboardLucio::removeKey(Key *) { /* TODO */
}

#include "cstring"
Key *KeyboardLucio::findKey(Symbol symbol) {
  for (char i = 0; i < this->keysCount; i++)
    if (strcmp(symbol,this->keys[i]->getSymbol()))
      return this->keys[i];

  throw "Key not found!";
}

void KeyboardLucio::setCpu(Cpu *cpu) { this->cpu = cpu; }

Cpu *KeyboardLucio::getCpu() { return this->cpu; }
