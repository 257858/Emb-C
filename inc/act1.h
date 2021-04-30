#include <avr/io.h>
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
