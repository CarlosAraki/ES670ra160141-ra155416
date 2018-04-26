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

/* ************************************************ */
/* Method name:        interpretState               */
/* Method description: intepreta e executa comandos */
/* dependendo do estado em que se encontra          */
/* Input params:       char cComando,char cEstado   */
/* Output params:      char                         */
/* ************************************************ */

char interpretCmd_interpretState(char cComando, char cEstado);


#endif  /* INTEPRETCMD_ */
