/**
 * @file project_main.c
 * @author Vaishnavi DV
 * @brief Project to Blink an LED when person sits and turns on the heater and adjusts the temperatue.
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
/** \brief main()
 *
 * \return int
 *
 */
#include <avr/io.h>
#include <util/delay.h>
#include "act1.h"
#include "act2.h"
#include "act3.h"
#include "act4.h"
int main(void)
{
    init1();//activity 1
    InitADC();//activity 2
    init3();//activity 3
    init4(103);//activity 4
    while(1)
    {
        uint16_t temp;
        char deg;
        led();//activity 1
        temp=ReadADC(0);//read from channel 0(activity 2)
        deg=pwm(temp);//activity 3
        uart_write_data(deg);//activity 4
    }

    return 0;
}
