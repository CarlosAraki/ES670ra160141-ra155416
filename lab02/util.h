/* ***************************************************************** */
/* File name:         util.h                                         */
/* File description: Header file containing the function/methods     */
/*                   prototypes of util.c                            */
/*                   Those delays were tested under the following:   */
/*                   PLLDIV = 1, FOSC = HSPLL_HS, CPUDIV = OSC1_PLL2 */
/*                   For the development kit McLab2                  */
/* Author name:      dloubach                                        */
/* Creation date:    09jan2015                                       */
/* Revision date:    26out2015                                       */
/* ***************************************************************** */

#ifndef UTIL_H
#define UTIL_H

/* ************************************************ */
/* Method name:        util_genDelay180us           */
/* Method description: generates ~ 180 micro sec    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay180us(void);


/* ************************************************ */
/* Method name:        util_genDelay500us           */
/* Method description: generates ~   500 micro sec  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay500us(void);


/* ************************************************ */
/* Method name:        util_genDelay1ms             */
/* Method description: generates ~   1 mili sec     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay1ms(void);


/* ************************************************ */
/* Method name:        util_genDelay10ms            */
/* Method description: generates ~   10 mili sec    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay10ms(void);


#endif /* UTIL_H */
