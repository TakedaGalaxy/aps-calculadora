#include "main.hpp"

int main()
{

  Cpu *cpu = new CpuTK();
  Keyboard *keyboard = new KeyboardTK();
  keyboard->setCpu(cpu);

  /* Definindo Digitos */
  struct SymbolDigit
  {
    Symbol symbol;
    Digit digit;
  };

  SymbolDigit symbolsDigits[] = {
      {"0", ZERO},
      {"1", ONE},
      {"2", TWO},
      {"3", THREE},
      {"4", FOUR},
      {"5", FIVE},
      {"6", SIX},
      {"7", SEVEN},
      {"8", EIGHT},
      {"9", NINE},
  };

  for (SymbolDigit i : symbolsDigits)
  {
    KeyDigit *key = new KeyDigitTK(i.symbol, i.digit);
    keyboard->addKey(key);
  }
  /* End */

  /* Definindo Operadores */
  struct SymbolOperator
  {
    Symbol symbol;
    Operator op;
  };

  SymbolOperator symbolsOperators[] = {
      {"+", SUM},
      {"-", SUBTRACTION},
      {"/", DIVISION},
      {"*", MULTIPLICATION},
      {"%", PERCENTAGE},
      {"sqr", SQUARE_ROOT},
  };

  for (SymbolOperator i : symbolsOperators)
  {
    KeyOperator *key = new KeyOperatorTK(i.symbol, i.op);
    keyboard->addKey(key);
  }
  /* End */

  /* Definindo Controle */
  struct SymbolControl
  {
    Symbol symbol;
    Control control;
  };

  SymbolControl symbolsControls[] = {
      {"on", ON},
      {"off", OFF},
      {"ce", CLEAR_ERROR},
      {"mrc", MEMORY_READ_CLEAR},
      {"msum", MEMORY_SUM},
      {"msub", MEMORY_SUBTRACTION},
      {"=", EQUAL},
      {".", DECIMAL_SEPARATOR},
  };

  for (SymbolControl i : symbolsControls)
  {
    KeyControl *key = new KeyControlTK(i.symbol, i.control);
    keyboard->addKey(key);
  }
  /* End */

  keyboard->findKey("1")->press();

  return 0;
}