#ifndef MY_UART_H
#define MY_UART_H

#include "UART.c"

void UART_init();
void UART_transmit(unsigned char);
void UART_transmit_string(const char *);
#endif // MY_UART_H
