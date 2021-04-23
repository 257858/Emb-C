/**
 * @file project_main.c
 * @author Vaishnavi DV
 * @brief Project to Blink an LED when both the sensors output is 1
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "head.h"


/**
 * @brief Main function where the code execution starts
 * 
 * @return int Return 0 if the program completes successfully
 * @PORTB0 is output pin
 * @PORTD0 is input pin
 * @PORTD1 is input pin
 * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
 */
int main(void)
{
    DDRB|=(1<<PB0);//PB0 is set as output
    DDRD&=~(1<<PD0);
    PORTD|=(1<<PD0);
    DDRD&=~(1<<PD1);
    PORTD|=(1<<PD1);
    while(1)
    {
        if(!(PIND &(1<<PD0)) & !(PIND &(1<<PD1))) //if both input is 1 then led is on
        {
            PORTB|=(1<<PB0);
            //_delay_ms(2000);
        }
        else//else led is off
        {
            PORTB&=~(1<<PB0);
            //_delay_ms(2000);
        }
    }

    return 0;
}



