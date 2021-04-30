#include <avr/io.h>
#include<util/delay.h>
FUSES = {
    .low = LFUSE_DEFAULT,
    .high = HFUSE_DEFAULT,
    .extended = EFUSE_DEFAULT
};

/** \brief function: act1 defines all the ports needed for activity1
 * \return void
 *
 */

void act1()
{
    DDRB|=(1<<PB0);//PB0 is set as output
    DDRD&=~(1<<PD0);
    PORTD|=(1<<PD0);
    DDRD&=~(1<<PD1);
    PORTD|=(1<<PD1);
}
/** \brief function: led() used to turn the led on only if two sensors are active
 * \return void
 *
 */
void led()
{
    if(!(PIND &(1<<PD0)) & !(PIND &(1<<PD1))) //if both input is 1 then led is on
        {
            PORTB|=(1<<PB0);
            _delay_ms(20);
        }
        else//else led is off
        {
            PORTB&=~(1<<PB0);
            _delay_ms(20);
        }
}
