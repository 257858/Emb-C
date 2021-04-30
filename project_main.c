/**
 * @file project_main.c
 * @author Vaishnavi DV
 * @brief Project to Blink an LED when person sits and turns on the heater and adjusts the temperatue
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */



/**
 * @brief Main function where the code execution starts
 * 
 * @return int Return 0 if the program completes successfully
 */
#include <avr/io.h>
#include<util/delay.h>
#include "act2.h"
int main(void)
{
    act1();
    InitADC();
    uint16_t temp;
    while(1)
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
        temp=ReadADC(0);//read from channel 0
    }

    return 0;
}
