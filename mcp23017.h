//
//  mcp23017.h
//  
//
//  Created by Tobias Ebsen on 28/05/18.
//
//

#ifndef mcp23017_h
#define mcp23017_hpp

#include <Arduino.h>



typedef enum {
    IODIRA,
    IODIRB,
    IPOLA,
    IPOLB,
    GPINTENA,
    GPINTENB,
    DEFVALA,
    DEFVALB,
    INTCONA,
    INTCONB,
    IOCON = 0x0A,
    GPPUA = 0x0C,
    GPPUB,
    INTFA = 0x0E,
    INTFB,
    GPIOA = 0x12,
    GPIOB,
} mcpReg;

#define MCP_INTPOL      2
#define MCP_ODR         4
#define MCP_HAEN        8
#define MCP_DISSLW      16
#define MCP_SEQOP       32
#define MCP_MIRROR      64
#define MCP_BANK        128


class MCP23017 {
public:
    MCP23017(uint8_t addr = 0x20);
    
    void setDirection(uint16_t mask); // IODIR
    void setPolarity(uint16_t mask); // IPOL
    void setInterrupt(uint16_t mask); // GPINTEN
    void setDefaultValue(uint16_t mask); // DEFVAL
    void setIntConfig(uint16_t mask); // INTCONA
    void setConfig(uint8_t mask); // IOCON
    void setPullUp(uint16_t mask); // GPPUA
    void setGpio(uint16_t mask); // GPIOA
    
    uint16_t getIntFlag();
    uint16_t getIntCapture();
    uint16_t getGpio();
    
    uint8_t getIntPort();
    uint8_t getIntValue();

private:
    void write(mcpReg reg, uint8_t data);
    void write(mcpReg reg, uint16_t data);
    uint16_t read(mcpReg reg);

    uint8_t addr;
};


#endif /* mcp23017_h */
