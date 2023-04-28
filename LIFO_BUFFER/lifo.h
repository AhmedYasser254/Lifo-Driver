/*
 * lifo.h
 *
 *  Created on: Apr 28, 2023
 *      Author: Ahmed Yasser
 */

#ifndef LIFO_H_
#define LIFO_H_

//type definitions for users

typedef struct {
unsigned int length;  //34an y4el integers
unsigned int count;   //34an ybnyly l buffer feh ad a
unsigned char* base;
unsigned char* head;
}LIFO_Buff_t;   //3mlto k data type 3ala tol mn no3 LIFO_BUff
/* to make more than lifo buffer for more than peripheral like UART,SPI*/

typedef enum{
	LIFO_No_Error,
	LIFO_Full,
	LIFO_Empty,	// LIFO is Empty to check when make the pop
	LIFO_Null   //The LIFO didn't exist
}LIFO_status;



//APIs
//We will start with the basics APIs to get started EASILY */
LIFO_status LIFO_Add_Item(LIFO_Buff_t* lifo_buf, unsigned int item);   //For Pushing the data and return the status of lifo

LIFO_status LIFO_Get_Data(LIFO_Buff_t* lifo_buf, unsigned int* item );

LIFO_status LIFO_init(LIFO_Buff_t* lifo_buf, unsigned int* buf , unsigned int length);




#endif /* LIFO_H_ */
