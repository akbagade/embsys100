//CPU freqency 16hz
#include <stdint.h>
#include "stm32f401xe.h"


void main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    GPIOA->ODR ^= GPIO_ODR_OD5;

    SysTick->LOAD = 15'999'999;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;

    while (1)
    {
    
    
    }
}

//end
