#include "tester.hpp"

void stop()
{
  std::cin.ignore();
}

void messageStop(const char *str, bool cls = 0)
{
  if (cls)
    system("cls");

  std::cout << str;
  stop();
}

void Tester::sum()
{
  messageStop("Testando soma de 152.50 + 8.25 = 160.75| Pressione enter !", 1);

  InterfaceConsole *console = new Console();
  InterfaceDisplay *display = new Display(console);
  InterfaceCpu *cpu = new Cpu();

  display->on();

  addNumberCpuDisplay(cpu, 1, display);
  addNumberCpuDisplay(cpu, 5, display);
  addNumberCpuDisplay(cpu, 2, display);

  addDotCpuDisplay(cpu, display);

  addNumberCpuDisplay(cpu, 5, display);
  addNumberCpuDisplay(cpu, 0, display);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  setOperationCpuDisplay(cpu, OP_SUM, display, SUM);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  addNumberCpuDisplay(cpu, 8, display);
  addDotCpuDisplay(cpu, display);
  addNumberCpuDisplay(cpu, 2, display);
  addNumberCpuDisplay(cpu, 5, display);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  doOperationCpuDisplay(cpu, display);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para finalizar teste!");
}

void Tester::sub()
{
  system("cls");
  std::cout << "Testando subtracao de 50 - 50.5 = 0.5 | Pressione enter !";
  std::cin.ignore();

  InterfaceConsole *console = new Console();
  InterfaceDisplay *display = new Display(console);
  InterfaceCpu *cpu = new Cpu();

  display->on();

  addNumberCpuDisplay(cpu, 5, display);
  addNumberCpuDisplay(cpu, 0, display);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  setOperationCpuDisplay(cpu, OP_SUM, display, SUBTRACTION);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  addNumberCpuDisplay(cpu, 5, display);
  addNumberCpuDisplay(cpu, 0, display);
  addDotCpuDisplay(cpu, display);
  addNumberCpuDisplay(cpu, 5, display);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  setOperationCpuDisplay(cpu, OP_SUB, display, SUBTRACTION);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para finalizar teste!");
}

void Tester::mult()
{
  system("cls");
  std::cout << "Testando multiplicacao de 25 * 0.5 = 12.5 | Pressione enter !";
  std::cin.ignore();

  InterfaceConsole *console = new Console();
  InterfaceDisplay *display = new Display(console);
  InterfaceCpu *cpu = new Cpu();

  display->on();

  addNumberCpuDisplay(cpu, 2, display);
  addNumberCpuDisplay(cpu, 5, display);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  setOperationCpuDisplay(cpu, OP_SUM, display, MULTIPLICATION);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  addNumberCpuDisplay(cpu, 0, display);
  addDotCpuDisplay(cpu, display);
  addNumberCpuDisplay(cpu, 5, display);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  setOperationCpuDisplay(cpu, OP_MULTIPLICATION, display, MULTIPLICATION);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para finalizar teste!");
}

void Tester::div()
{
  system("cls");
  std::cout << "Testando divisao de 125.5 / 5 = 25.1 | Pressione enter !";
  std::cin.ignore();

  InterfaceConsole *console = new Console();
  InterfaceDisplay *display = new Display(console);
  InterfaceCpu *cpu = new Cpu();

  display->on();

  addNumberCpuDisplay(cpu, 1, display);
  addNumberCpuDisplay(cpu, 2, display);
  addNumberCpuDisplay(cpu, 5, display);

  addDotCpuDisplay(cpu, display);

  addNumberCpuDisplay(cpu, 5, display);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  setOperationCpuDisplay(cpu, OP_SUM, display, DIVISION);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  addNumberCpuDisplay(cpu, 5, display);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para continuar!");

  setOperationCpuDisplay(cpu, OP_DIVISION, display, DIVISION);

  console->setPixel(0, 12, EMPTY);
  messageStop("Pressione enter para finalizar teste!");
}