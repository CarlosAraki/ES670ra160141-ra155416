/* ***************************************************************** */
/* File name:        interpretCmd.h                                  */
/* File description: Interpretador de estados para LED E Switch      */
/* Author name:      Carlos Vinicius Araki Oliveira       RA:160141  */
/*                   Gabriel Bonani Machado               RA:155416  */
/* Creation date:    19abr2018                                       */
/* Revision date:    26abr2018                                       */
/* ***************************************************************** */

#ifndef INTERPRETCMD_
#define INTERPRETCMD_

#include "..\PID\pid.h"

/* ************************************************ */
/* Method name:        interpretState               */
/* Method description: Printa valor no serial       */
/* Input params:       char cComando				*/
/* Output params:      n\a                          */
/* ************************************************ */

void measure_StringSerial(int iCont);

/* ************************************************ */
/* Method name:        interpretState               */
/* Method description: intepreta e executa comandos */
/* dependendo do estado em que se encontra          */
/* Input params:       char cComando				*/
/* Output params:      n\a                          */
/* ************************************************ */

void interpretCmd_interpretState(char cComando,PID_DATA *pid_data);

#endif  /* INTEPRETCMD_ */
