#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "UART.h"
#include "bluetooth.h"

#define BUZZER PB5
#define IR_SENSOR PB2
#define F_CPU 16000000UL

volatile char data;
volatile uint8_t cmp_flag = 0;

int main()
{
  uint8_t monitor_door = 0;
  
  UART_init();
  set_bluetooth_name("RSA");
  DDRB |= (1<<BUZZER);
  DDRB &= ~(1<<IR_SENSOR);
  while(1)
  {
      if(cmp_flag)
      {
        cmp_flag=0;
        if(data=='E')
          monitor_door = 1;
        else if(data=='D')
          monitor_door = 0;
      }
      if(monitor_door)
      {
        if(PINB&(1<<IR_SENSOR))
          PORTB |=(1<<BUZZER);
        else
          PORTB &=~(1<<BUZZER);
      }
      else if(!monitor_door)
        PORTB &=~(1<<BUZZER);
  }
  return 0;
}

// USART Receive Complete Interrupt Service Routine (ISR)
ISR(USART_RX_vect) 
{
    data = UDR0;
    cmp_flag=1;
}
