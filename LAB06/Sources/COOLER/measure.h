/*
 * measure.h
 *
 *  Created on: 07/05/2018
 *      Author: CarlosAraki & Gabriel Bonani
 */

#ifndef  SOURCES_MEASURE_H_
#define  SOURCES_MEASURE_H_

/* ************************************************ */
/* Method name:        measure_Init                 */
/* Method description:Initialize TPM0 and tachometer*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void measure_Init(void);

/* ************************************************ */
/* Method name:        measure_Cont                 */
/* Method description: Return TPM0_CNT Value        */
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      int  iCont                   */
/* ************************************************ */
int measure_Cont(void);

/* ************************************************ */
/* Method name:        counter_String               */
/* Method description:Transform int iCont in LCD     */
/* string                                           */
/* function  										*/
/* Input params:       int iCont                     */
/* Output params:      n/a                          */
/* ************************************************ */
void measure_String(int iCont);

#endif /*_MEASURE_H_ */
