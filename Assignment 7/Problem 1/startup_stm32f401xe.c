//Start the iar using the external call

#include <stdint.h>
#include <stdlib.h>
#include "stm32f401xe.h"


extern void* CSTACK$$Limit;
extern void* __iar_program_start;


void DefaultHandler(void);
void SysTickHandler(void);


void* const __vector_table[] @ ".intvec" =
{
    &CSTACK$$Limit,
    &__iar_program_start,

    (void*) DefaultHandler,     
    (void*) DefaultHandler,     
    (void*) DefaultHandler,     
    (void*) DefaultHandler,    
    (void*) DefaultHandler,    
    (void*) DefaultHandler,     
    (void*) DefaultHandler,    
    (void*) DefaultHandler,    
    (void*) DefaultHandler,    
    (void*) DefaultHandler,    
    (void*) DefaultHandler,    
    (void*) DefaultHandler,    
    (void*) DefaultHandler,    
    (void*) SysTickHandler,    
    
    
};

void DefaultHandler()
{
    while (1)
    {
    
    
    }
}

void SysTickHandler()
{
    GPIOA->ODR ^= GPIO_ODR_OD5;
}

//end
