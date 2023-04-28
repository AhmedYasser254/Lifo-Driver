/*
 * main.c
 *
 *  Created on: Apr 28, 2023
 *      Author: Ahmed Yasser
 */



#include "stdio.h"
#include "lifo.h"
#include "stdlib.h"

unsigned int buffer1 [5];  // 5*4 = 20Bytes


int main()
{
	int temp =0;
	LIFO_Buff_t uart_lifo, I2C_lifo;


	//static allocation
	LIFO_init(&uart_lifo, buffer1,7);

	//Dynamic allocation
	//Dynamic buffer
	unsigned int *buffer2 = (unsigned int *)malloc(5 * sizeof(unsigned int));
	LIFO_init(&I2C_lifo, buffer2,5);

	for(int i =0; i<7; i++)
	{
		if(LIFO_Add_Item(&uart_lifo, i) == LIFO_No_Error)
		{
			printf(" UART_LIFO add : %d \n ",i);
		}
	}
	for(int i =0; i<7; i++)
	{
		if(	LIFO_Get_Data(&uart_lifo, (unsigned int*)&temp) == LIFO_No_Error)
		{
			printf("\n\nUART_LIFO add : %d \n ",temp);
		}
	}
	return 0;
}
