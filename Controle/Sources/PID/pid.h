/*
 * pid.h
 *
 *  Created on: 21/06/2018
 *      Author: aluno
 */

#ifndef SOURCES_PID_PID_H_
#define SOURCES_PID_PID_H_


typedef struct PID_DATA{

	double Pgain,Dgain,Igain;
	double sensor_value_previous;
	double error_sum;
}PID_DATA;
/* ************************************************ */
/* Method name:        pid_init                     */
/* Method description: seta valores iniciais        */
/* Input params:       vector unsigned bits         */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_init(PID_DATA *pid_data);
/* ************************************************ */
/* Method name:        pid_Set                      */
/* Method description:seta referência               */
/* Input params:       int iValor                   */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_Set(int iValor);
/* ************************************************ */
/* Method name:        pid_Control                  */
/* Method description: controle pid                 */
/* Input params:       PID_DATA *pid_data           */
/*                     double sensor_value          */
/* Output params:      n/a                          */
/* ************************************************ */
double pid_Control(PID_DATA *pid_data, double sensor_value);

#endif
