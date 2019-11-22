#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA (1<<5)

volatile int counter=0;

void main(void)
{
    
    *((unsigned int*)((0x42000000) + (0x23830*32) + (0*4))) = 0x1;
  

    *((unsigned int*)((0x42000000) + (0x20000*32) + (10*4))) = 0x1; 

     
    while(1)
    {
    counter=0;

    while (counter < 1000000) //setting counter for 1 secound
    {
      counter++;
    }
    //This is set to 1 to enable the pin
    *((unsigned int*)((0x42000000) + (0x20014*32) + (5*4))) = 0x1; 
        
    counter=0;
    
    while (counter < 1000000)  //setting counter for 1 secound
    {
      counter++;
    }
    //This is set to 1 to disable the pin
    *((unsigned int*)((0x42000000) + (0x20014*32) + (5*4))) = 0x0; 
    
    }
}
