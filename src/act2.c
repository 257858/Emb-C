#include <avr/io.h>
/** \brief InitADC(): initializing all ports for ADC
 * \return void
 *
 */
void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
/** \brief ReadADC: used to read the values from the selected channels
 *
 * \param ch: channel no
 * \return ADC value which is unsigned int 16 bits
 *
 */

uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0Xf8;
    ch=ch&0b00000111;
    ADMUX=ch;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}
