#include "main.hpp"

Sysmbol converIntToSysmbol(unsigned int number)
{
  const Sysmbol table[10] = {
      ZERO,
      ONE,
      TWO,
      THREE,
      FOUR,
      FIVE,
      SIX,
      SEVEN,
      EIGHT,
      NINE,
  };
  return table[number];
}

void doOperationCpuDisplay(InterfaceCpu *cpu, InterfaceDisplay *display)
{
  cpu->doOperation();
  Memory result = cpu->getResult();
  display->clearResult();
  display->clear();
  if (result.negative)
    display->setNegativeResult();
  else
    display->setPositiveResult();

  for (int i = 0; i < MAX_MEMORY; i++)
  {
    if (i == MAX_MEMORY - result.dot)
      display->addOnResult(SY_DOT);
    display->addOnResult(converIntToSysmbol(result.v[i]));
    display->render();
  }
}

void setOperationCpuDisplay(InterfaceCpu *cpu, Operation op, InterfaceDisplay *display, OperationSysmbol sysOp)
{
  cpu->setOperation(op);
  Memory result = cpu->getResult();
  display->clear();
  display->clearResult();
  if (result.negative)
    display->setNegativeResult();
  else
    display->setPositiveResult();
  for (int i = 0; i < MAX_MEMORY; i++)
  {
    if (i == MAX_MEMORY - result.dot)
      display->addOnResult(SY_DOT);
    display->addOnResult(converIntToSysmbol(result.v[i]));
    display->render();
  }
  display->setOperation(sysOp);
  display->render();
}

void addNumberCpuDisplay(InterfaceCpu *cpu, unsigned int number, InterfaceDisplay *display)
{
  cpu->add(number);
  display->add(converIntToSysmbol(number));
  display->render();
}

void addDotCpuDisplay(InterfaceCpu *cpu, InterfaceDisplay *display)
{
  cpu->addDot();
  display->add(SY_DOT);
  display->render();
}


int main()
{

  InterfaceConsole *console = new Console();

  InterfaceDisplay *display = new Display(console);

  InterfaceCpu *cpu = new Cpu();

  display->on();

  addNumberCpuDisplay(cpu, 1, display);
  addNumberCpuDisplay(cpu, 2, display);
  addNumberCpuDisplay(cpu, 3, display);

  addDotCpuDisplay(cpu, display);

  addNumberCpuDisplay(cpu, 3, display);
  addNumberCpuDisplay(cpu, 9, display);

  setOperationCpuDisplay(cpu, OP_SUM, display, SUBTRACTION);

  addNumberCpuDisplay(cpu, 2, display);
  addNumberCpuDisplay(cpu, 2, display);
  addNumberCpuDisplay(cpu, 3, display);

  setOperationCpuDisplay(cpu, OP_SUB, display, SUBTRACTION);

  return 0;
}