//
//  mcp23017.cpp
//  
//
//  Created by Tobias Ebsen on 28/05/18.
//
//

#include "mcp23017.h"

#if defined(CORE_TEENSY) && ( defined(__MK20DX128__) || defined(__MK20DX256__) || defined(__MKL26Z64__) || defined(__MK64FX512__) || defined(__MK66FX1M0__))       // Teensy 3.X
#include <i2c_t3.h>
#else
#include <Wire.h>
#endif


MCP23017::MCP23017(uint8_t addr) {
    this->addr = addr;
}

void MCP23017::setDirection(uint16_t mask) {
    write(mcpReg::IODIRA, mask);
}

void MCP23017::setPolarity(uint16_t mask) {
    write(mcpReg::IPOLA, mask);
}

void MCP23017::setInterrupt(uint16_t mask) {
    write(mcpReg::GPINTENA, mask);
}

void MCP23017::setDefaultValue(uint16_t mask) {
    write(mcpReg::DEFVALA, mask);
}

void MCP23017::setIntConfig(uint16_t mask) {
    write(mcpReg::INTCONA, mask);
}

void MCP23017::setConfig(uint8_t mask) {
    write(mcpReg::IOCON, mask);
}

void MCP23017::setPullUp(uint16_t mask) {
    write(mcpReg::GPPUA, mask);
}

void MCP23017::setGpio(uint16_t mask) {
    write(mcpReg::GPIOA, mask);
}

uint16_t MCP23017::getGpio() {
    return read(mcpReg::GPIOA);
}

// private:

void MCP23017::write(mcpReg reg, uint8_t data) {
    Wire.beginTransmission(addr);
    Wire.write((uint8_t)reg);
    Wire.write((uint8_t)data);
    Wire.endTransmission();
}

void MCP23017::write(mcpReg reg, uint16_t data) {
    Wire.beginTransmission(addr);
    Wire.write((uint8_t)reg);
    Wire.write((uint8_t)(data & 0xFF));
    Wire.write((uint8_t)(data >> 8));
    Wire.endTransmission();
}

uint16_t MCP23017::read(mcpReg reg) {
    Wire.beginTransmission(addr);
    Wire.write((uint8_t)reg);
    Wire.endTransmission();
    
    Wire.requestFrom(addr, 2);
    return Wire.read() | (Wire.read() << 8);
}
