#include <avr/io.h>
/**
 * \brief init4():initializes ports for UART
 *
 * \param value
 * \return void
 */
void init4(uint16_t value)
{

    UBRR0L = value;
    UBRR0H = (value>>8)&(0x00ff);
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ01);

    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}
/** \brief uart_write_data: outputs the data using UART
 *
 * \param input:data of type char
 * \return void
 *
 */

void uart_write_data(char data)
{
    while(!(UCSR0A & (1<<UDRE0)))
    {

    }
    UDR0 = data;
}
