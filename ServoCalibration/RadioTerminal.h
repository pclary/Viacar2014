#ifndef RADIOTERMINAL_H
#define RADIOTERMINAL_H

#define INPUT_BUFFER_MAX 32
#define NUM_COMMANDS_MAX 16

#define USB_SERIAL_ENABLE


class CmdHandler
{
public:
    virtual ~CmdHandler() {}
    virtual void sendChar(char c) {}
};


namespace RadioTerminal
{
    void initialize(int csnPin, int cePin, int irqPin);
    void reset();
    void addCommand(const char* cmdString, CmdHandler* (*fpointer)(const char*) );
    void terminateCmd();
    void write(const char* string);
    
    extern volatile uint32_t rx_controller;
    
    extern uint8_t controller;
    extern uint8_t channel;
    extern uint32_t controllerBaseAddress;
    extern uint32_t rxAddress;
    extern uint32_t txAddress;
};

#endif // RADIOTERMINAL_H