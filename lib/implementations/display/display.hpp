#pragma once

#include "../../interfaces/interface-display.hpp"
#include "../../interfaces/interface-console.hpp"

struct SysmboysStatus
{
  bool memoryClear;
  bool memoryRead;
  bool memoryPlus;
  bool memorySub;
  bool memorySave;
};

const bool SysmboyShape[12][15] = {
    // ZERO
    {1, 1, 1,
     1, 0, 1,
     1, 0, 1,
     1, 0, 1,
     1, 1, 1},
    // ONE,
    {0, 1, 0,
     1, 1, 0,
     0, 1, 0,
     0, 1, 0,
     1, 1, 1},
    // TWO,
    {1, 1, 1,
     0, 0, 1,
     1, 1, 1,
     1, 0, 0,
     1, 1, 1},
    // THREE,
    {1, 1, 1,
     0, 0, 1,
     0, 1, 1,
     0, 0, 1,
     1, 1, 1},
    // FOUR,
    {1, 0, 1,
     1, 0, 1,
     1, 1, 1,
     0, 0, 1,
     0, 0, 1},
    // FIVE,
    {1, 1, 1,
     1, 0, 0,
     1, 1, 1,
     0, 0, 1,
     1, 1, 1},
    // SIX,
    {1, 1, 1,
     1, 0, 0,
     1, 1, 1,
     1, 0, 1,
     1, 1, 1},
    // SEVEN,
    {1, 1, 1,
     0, 0, 1,
     0, 0, 1,
     0, 1, 0,
     0, 1, 0},
    // EIGHT,
    {1, 1, 1,
     1, 0, 1,
     1, 1, 1,
     1, 0, 1,
     1, 1, 1},
    // NINE,
    {1, 1, 1,
     1, 0, 1,
     1, 1, 1,
     0, 0, 1,
     1, 1, 1},
    // NONE
    {0, 0, 0,
     0, 0, 0,
     0, 0, 0,
     0, 0, 0,
     0, 0, 0},
    // DOT
    {0, 0, 0,
     0, 0, 0,
     0, 0, 0,
     0, 0, 0,
     0, 1, 0},
};

const bool OperationSysmboyShape[7][15] = {
    // NONE,
    {0, 0, 0,
     0, 0, 0,
     0, 0, 0,
     0, 0, 0,
     0, 0, 0},
    // SUM,
    {0, 0, 0,
     0, 1, 0,
     1, 1, 1,
     0, 1, 0,
     0, 0, 0},
    // SUBTRACTION,
    {0, 0, 0,
     0, 0, 0,
     1, 1, 1,
     0, 0, 0,
     0, 0, 0},
    // DIVISION,
    {0, 0, 1,
     0, 0, 1,
     0, 1, 0,
     1, 0, 0,
     1, 0, 0},
    // MULTIPLICATION,
    {0, 0, 0,
     1, 0, 1,
     0, 1, 0,
     1, 0, 1,
     0, 0, 0},
    // PERCENTAGE,
    {1, 0, 1,
     0, 0, 1,
     0, 1, 0,
     1, 0, 0,
     1, 0, 1},
    // SQUARE_ROOT
    {0, 1, 1,
     0, 1, 0,
     0, 1, 0,
     1, 1, 0,
     0, 1, 0}};

class Display : public InterfaceDisplay
{
private:
  InterfaceConsole *console;
  SysmboysStatus sysmboysStatus = {0, 0, 0, 0, 0};
  bool displayOn = false;

  static const int MAX_DIGITS = 16;

  Sysmbol resultBuffer[MAX_DIGITS] = {SPACE};
  Sysmbol valueBuffer[MAX_DIGITS] = {SPACE};
  OperationSysmbol operationBuffer = NONE;

  void drawDigit(int x, int y, const bool digit[15]);

  bool negativeResult = 0;

public:
  Display(InterfaceConsole *interfaceConsole);

  virtual void on();
  virtual void off();
  virtual void reset();
  virtual void clear();

  virtual void addOnResult(Sysmbol);
  virtual void setOnResult(Sysmbol *, int n);
  virtual void clearResult();

  virtual void add(Sysmbol);
  virtual void set(Sysmbol *, int n);

  virtual void setOperation(OperationSysmbol);

  virtual void setOn(IndicatorSysmbol);
  virtual void setOff(IndicatorSysmbol);

  virtual void render();

  virtual void setNegativeResult();
  virtual void setPositiveResult();
};