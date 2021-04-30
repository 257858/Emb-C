#include <avr/io.h>
#include<util/delay.h>
void init3()
{
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B|=(1<<WGM12)|(1<<CS11);
    DDRB|=(1<<PB1);
}

void pwm(uint16_t temp)
{
            if(temp<200)
        {
            OCR1A=20;
            _delay_ms(20);
        }
        else if(temp<500)
        {
            OCR1A=25;
            _delay_ms(20);
        }
        else if(temp<700)
        {
            OCR1A=29;
            _delay_ms(20);
        }
        else if(temp<1024)
        {
            OCR1A=25;
            _delay_ms(33);
        }
}
