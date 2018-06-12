#ifndef HEATER_HAL_
#define HEATER_HAL_

/* ************************************************** */
/* Method name: 	 heater_hal_StateMachine      */
/* Method description:  maquina de estados do sensor  */
/*			 de temp		      */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 			      */
/* ************************************************** */
void heater_hal_StateMachine(void);

/* ************************************************** */
/* Method name: 	 heater_hal_getTemp	      */
/* Method description:  retorna o valor conv na temp  */
/* Input params:	   n/a 			      */
/* Outpu params:	   int iTemp		      */
/* ************************************************** */

int  heater_hal_getTemp();
//Criar struct de dados
//Criar get_heater_hal

#endif
