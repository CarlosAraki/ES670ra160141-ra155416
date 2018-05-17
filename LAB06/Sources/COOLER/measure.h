/*
 * measure.h
 *
 *  Created on: 07/05/2018
 *      Author: aluno
 */

#ifndef  SOURCES_MEASURE_H_
#define  SOURCES_MEASURE_H_

/* ************************************************ */
/* Method name:        counter_init                 */
/* Method description:Initialize TPM0 and tachometer*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void counter_init(void);

/* ************************************************ */
/* Method name:        counter_cont                 */
/* Method description: Return TPM0_CNT Value        */
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      int  icont                   */
/* ************************************************ */
int counter_cont(void);

/* ************************************************ */
/* Method name:        counter_String               */
/* Method description:Transform int cont in LCD     */
/* string                                           */
/* function  										*/
/* Input params:       int cont                     */
/* Output params:      n/a                          */
/* ************************************************ */
void counter_String(int iCont);

#endif /*_MEASURE_H_ */
