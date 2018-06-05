/* ***************************************************************** */
/* File name:        timer_counter.h                                 */
/* File description: cooler metodos para pwm                         */
/* Author name:      Carlos Vinicius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    05jun2018                                       */
/* Revision date:    ----------                                      */
/* ***************************************************************** */



#ifndef SOURCES_TIMER_COUNTER_H_
#define SOURCES_TIMER_COUNTER_H_

/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM            */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			                  */
/* Outpu params:	   n/a 		                      */
/* ************************************************** */
void timer_initTPM1AsPWM(unsigned int i);

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_coolerfan_init(void);

#endif /* SOURCES_TIMER_COUNTER_H_ */
