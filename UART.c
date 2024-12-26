#ifndef MY_UART_C
#define MY_UART_C

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 16000000UL  // Define clock frequency (16 MHz)
#define BAUD 9600
#define MY_UBRR F_CPU/16/BAUD-1

// Initialize UART
void UART_init() 
{
    unsigned int ubrr = MY_UBRR;
    UBRR0H = (unsigned char)(ubrr >> 8);  // Set baud rate high byte
    UBRR0L = (unsigned char)ubrr;         // Set baud rate low byte
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);  // Enable RX, TX, and RX Complete Interrupt
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  // 8 data bits, 1 stop bit
    SREG |= (1<<7);  // Enable global interrupts
}

// Transmit a single character
void UART_transmit(unsigned char data)
{
    while (!(UCSR0A & (1 << UDRE0)));  // Wait for transmit buffer to be empty
    UDR0 = data;  // Put data into buffer, sends the data
}

// Transmit a string
void UART_transmit_string(const char *str) 
{
    while (*str) 
    {
        UART_transmit(*str++);
    }
}
#endif // MY_UART_C
