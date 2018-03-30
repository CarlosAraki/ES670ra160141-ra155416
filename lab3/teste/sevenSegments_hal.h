/* ***************************************************************** */
/* File name:        SevenSegments_hal.c                              */
/* File description: This file has a couple of useful functions to   */
/*                   write "Hello" in 7seg from peripheral board     */
/* Author name:      Carlos Vinícius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    26/03/2018                                      */
/* Revision date:    ----------                                      */
/* ***************************************************************** */

#ifndef SOURCES_SEVENSEGMENTS_HAL_H_
#define SOURCES_SEVENSEGMENTS_HAL_H_

/* ************************************************ */
/* Method name:        segInit7Seg                  */
/* Method description: Initialize the segments and  */
/* the displays                                     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void segInit7Seg(void);

/* ************************************************ */
/* Method name:        setSegO                      */
/* Method description: this function Write a O in   */
/* 7seg                                             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void setSegO(void);


/* ************************************************ */
/* Method name:        setSegL                      */
/* Method description: this function Write a l l in */
/* 7seg                                             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void setSegL(void);


/* ************************************************ */
/* Method name:        setSegE                      */
/* Method description: this function Write a E in   */
/* 7seg                                             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */


void setSegE(void);

/* ************************************************ */
/* Method name:        setSegH                      */
/* Method description: this function Write a H in   */
/* 7seg                                             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void setSegH(void);


/* ************************************************ */
/* Method name:        clearSeg                     */
/* Method description: this function clear the      */
/* display                                          */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void clearSeg(void);
