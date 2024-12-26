#ifndef MY_BLUETOOTH_C
#define MY_BLUETOOTH_C
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void set_bluetooth_name(const char *name) 
{
    UART_transmit_string("AT+NAME=");
    UART_transmit_string(name);
    UART_transmit('\r');
}
#endif // MY_BLUETOOTH_C
