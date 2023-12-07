#pragma once

enum Sysmbol
{
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
  SPACE,
  SY_DOT,
};

enum OperationSysmbol
{
  NONE,
  SUM,
  SUBTRACTION,
  DIVISION,
  MULTIPLICATION,
  PERCENTAGE,
  SQUARE_ROOT
};

enum IndicatorSysmbol
{
  MEMORY_CLEAR,
  MEMORY_READ,
  MEMORY_PLUS,
  MEMORY_SUB,
  MEMORY_SAVE
};

class InterfaceDisplay
{
public:
  virtual void on() = 0;
  virtual void off() = 0;
  virtual void reset() = 0;

  virtual void addOnResult(Sysmbol) = 0;
  virtual void setOnResult(Sysmbol *, int n) = 0;
  virtual void clearResult() = 0;

  virtual void add(Sysmbol) = 0;
  virtual void set(Sysmbol *, int n) = 0;
  virtual void clear() = 0;

  virtual void setOperation(OperationSysmbol) = 0;

  virtual void setOn(IndicatorSysmbol) = 0;
  virtual void setOff(IndicatorSysmbol) = 0;

  virtual void render() = 0;

  virtual void setNegativeResult() = 0;
  virtual void setPositiveResult() = 0;
};