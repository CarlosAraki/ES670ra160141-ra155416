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
/* Method name:        setSegO                      */
/* Method description: this function Write a O in   */
/* 7seg                                             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void sevenSegments_setSegO(void);


/* ************************************************ */
/* Method name:        setSegL                      */
/* Method description: this function Write a l l in */
/* 7seg                                             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void sevenSegments_setSegL(void);


/* ************************************************ */
/* Method name:        setSegE                      */
/* Method description: this function Write a E in   */
/* 7seg                                             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */


void sevenSegments_setSegE(void);

/* ************************************************ */
/* Method name:        setSegH                      */
/* Method description: this function Write a H in   */
/* 7seg                                             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void sevenSegments_setSegH(void);

/* ************************************************ */
/* Method name:        setSegError                  */
/* Method description: this function Write only one */
/*segC in display									*/
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

void sevenSegments_setSeg(char C);
