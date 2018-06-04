/* ***************************************************************** */
/* File name:        cooler_hal.h                                    */
/* File description: cooler metodos                                  */
/* Author name:      Carlos Vinicius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    26mar2018                                       */
/* Revision date:    ----------                                      */
/* ***************************************************************** */
#ifndef SOURCES_COOLER_HAL_H_
#define SOURCES_COOLER_HAL_H_

/* ************************************************ */
/* Method name:        cooler_init                  */
/* Method description: Initialize the cooler		*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void cooler_Init(void);



/* ************************************************ */
/* Method name:        cooler_SetPin                */
/* Method description: Set cooler like GPIO 		*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void cooler_SetPin(void);

/* ************************************************ */
/* Method name:        cooler_ClearPin              */
/* Method description: Clear cooler like GPIO 		*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void cooler_ClearPin(void);


#endif /* SOURCES_COOLER_HAL_H_ */

