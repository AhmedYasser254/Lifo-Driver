/*************************************
 * file name: lifo.c
 *
 * Created on: Apr 28, 2023
 *
 * Author: Ahmed Yasser
 *
 *********************************/



#include "stdio.h"
#include "lifo.h"
#include "stdlib.h"
LIFO_status LIFO_Add_Item(LIFO_Buff_t* lifo_buf, unsigned int item)  //For Pushing the data and return the status of lifo
{
	// Check LIFO is Valid or not
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;


	// Check LIFO is FUll or not
	if(lifo_buf->head >= (lifo_buf->base + (lifo_buf->length * 4)))
		return LIFO_Full;
	/*
	if(lifo_buf->count == lifo_buf->length)
		return LIFO_Full;
	 */
	//add value
	*(lifo_buf->head) = item;
	lifo_buf->head ++;
	lifo_buf->count ++;
	return LIFO_No_Error;
}
LIFO_status LIFO_Get_Data(LIFO_Buff_t* lifo_buf, unsigned int* item )
{
	// Check if the LIFO is Valid or not
	if( !lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;


	// Check if the LIFO is Empty
	if(lifo_buf->base == lifo_buf->head)
		return LIFO_Empty;



	lifo_buf->head --;
	*item = *(lifo_buf->head);
	lifo_buf->count ++;

	return LIFO_No_Error;
}



LIFO_status LIFO_init(LIFO_Buff_t* lifo_buf, unsigned int* buf , unsigned int length)
{
	if (buf == NULL)
		return LIFO_Null;

	lifo_buf->base =  buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;
	return LIFO_No_Error;

}
