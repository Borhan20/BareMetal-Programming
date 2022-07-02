#include "main.h"
void configGPIO();
int main()
{
	configGPIO();
	while(1)
	{
		if(((GPIOA -> IDR >> 1) & 1) == 1)
		{
			GPIOA -> ODR |= (1 << 4);
			GPIOA -> ODR |= (1 << 5);

		}
		else
		{
			GPIOA -> ODR = 0;
		}
	}
}
void configGPIO()
{
	RCC -> AHB1ENR |= 1;
	GPIOA -> MODER |= (1 << 8);
	GPIOA -> MODER |= (1 << 10);
	GPIOA -> OSPEEDR |= (1 << 2) | (1 << 4) | (1 << 5);
}