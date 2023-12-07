#pragma once

#include "../interfaces/interface-console.hpp"
#include "../interfaces/interface-display.hpp"
#include "../interfaces/interface-cpu.hpp"

Sysmbol converIntToSysmbol(unsigned int number);

void doOperationCpuDisplay(InterfaceCpu *cpu, InterfaceDisplay *display);

void setOperationCpuDisplay(InterfaceCpu *cpu, Operation op, InterfaceDisplay *display, OperationSysmbol sysOp);

void addNumberCpuDisplay(InterfaceCpu *cpu, unsigned int number, InterfaceDisplay *display);

void addDotCpuDisplay(InterfaceCpu *cpu, InterfaceDisplay *display);