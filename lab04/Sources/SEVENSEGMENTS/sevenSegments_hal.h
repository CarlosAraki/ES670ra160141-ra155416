/* ***************************************************************** */
/* File name:        sevenSegments_hal.c                              */
/* File description: This file has a couple of useful functions to   */
/*                   write "Hello" in 7seg from peripheral board     */
/* Author name:      Carlos Vinícius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    26/03/2018                                      */
/* Revision date:    ----------                                      */
/* ***************************************************************** */



/* ************************************************ */
/* Method name:        segInit7Seg                  */
/* Method description: Initialize the segments and  */
/* the displays                                     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void sevenSegments_segInit7Seg(void);


/* ************************************************ */
/* Method name:        setSegPin                    */
/* Method description: this function Write a in pin */
/* Input params:       vector unsigned bits         */
/* Output params:      n/a                          */
/* ************************************************ */

void  sevenSegments_setSegPin(char cPin);

/* ************************************************ */
/* Method name:        setSegDisplay                */
/* Method description: this function Write in       */
/*    selected Disp                                 */
/* Input params:       char selected                */
/* Output params:      n/a                          */
/* ************************************************ */

void  sevenSegments_setSegDisplay(char cSelected);

/* ************************************************ */
/* Method name:        clearSeg                     */
/* Method description: this function clear the      */
/* display                                          */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */


void sevenSegments_clearSeg(void);

/* ************************************************ */
/* Method name:        setSeg                     	*/
/* Method description: this function write char c 	*/
/* in Display                                       */
/* Input params:       char C                       */
/* Output params:      n/a                          */
/* ************************************************ */

void sevenSegments_setSeg(char cPin,char cSelected);
