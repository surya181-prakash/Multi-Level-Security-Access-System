#include<LPC21xx.h>
void Init_Motor(void)
{
    IO0DIR |= (1 << 21) | (1 << 22) | (1 << 23); // Set pins as output
   // IO0CLR = (1 << 21) | (1 << 22) // Initially low 
   	IOSET0= (1 << 23); 
}
void Motor_Open(void)
{
    IO0SET = (1 << 21); // IN1 = 1
    IO0CLR = (1 << 22); // IN2 = 0
    
}

void Motor_Close(void)
{
    IO0CLR = (1 << 21); // IN1 = 0
    IO0SET = (1 << 22); // IN2 = 1
    
}

void Motor_Stop(void)
{
    IOSET0 = (1 << 21) | (1 << 22) | (1 << 23); // Disable all
}
