#include "main.hpp"


int main()
{

  InterfaceTester *tester = new Tester();


  tester->sum();

  tester->sub();
  
  tester->mult();

  tester->div();

  return 0;
}