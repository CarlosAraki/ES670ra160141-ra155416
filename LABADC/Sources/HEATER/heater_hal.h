#ifndef HEATER_HAL_
#define HEATER_HAL_

/* ************************************************** */
/* Method name: 	 heater_hal_StateMachine          */
/* Method description:  maquina de estados do sensor  */
/*			 de temp		                          */
/* Input params:	   n/a 			                  */
/* Outpu params:	   n/a 			                  */
/* ************************************************** */
void heater_hal_StateMachine(void);


/* ************************************************ */
/* Method name:        heater_hal_getTemp           */
/* Method description: pega valor da temperatura    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

int  heater_hal_getTemp(void);

/* ************************************************ */
/* Method name:        heater_hal_getRaw            */
/* Method description: pega o valor na tabela de    */
/* convercao                                        */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int heater_hal_getRaw(void);

#endif
