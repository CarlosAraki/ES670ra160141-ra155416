/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* ***************************************************************** */
/* File name:        main.c                                          */
/* File description: Programa Principal	                             */
/* Author name:      Carlos Vinicius Araki Oliveira       RA:160141  */
/*                   Gabriel Bonani Machado               RA:155416  */
/* Creation date:    12mar2018                                       */
/* Revision date:    05jun2018                                       */
/* ***************************************************************** */

#include "fsl_device_registers.h"
#include "PERIPHERAL/es670_peripheral_board.h"
#include "SERIAL/mcg_hal.h"
#include "SERIAL/debugUart.h"
#include "SERIAL/interpretCmd.h"
#include "UTIL/util.h"
#include "UTIL/tc_hal.h"
#include "fsl_debug_console.h"
#include "LEDSWITCH/ledswi_hal.h"
#include "BUZZER/buzzer_hal.h"
#include "SEVENSEGMENTS/sevenSegments_hal.h"
#include "LCD/lcd_hal.h"
#include "COOLER/cooler_hal.h"
#include "COOLER/measure.h"
#include "COOLER/timer_counter.h"
#include "HEATER/timer_counter.h"



/* system includes */
#include "fsl_debug_console.h"

/* globals */
volatile unsigned int uiFlagNextPeriod = 0;         /* cyclic executive flag */
volatile unsigned int uiTempCelsius = 0;
/* ************************************************ */
/* Method name:        main_cyclicExecuteIsr        */
/* Method description: cyclic executive interrupt   */
/*                     service routine              */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void main_cyclicExecuteIsr(void)
{
    /* set the cyclic executive flag */
    uiFlagNextPeriod = 1;
}

/****************************************************/
/* Method name:        main_cyclicExecuteIsr        */
/* Method description: interpretCmd interrupt 		*/
/*                     service routine              */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/****************************************************/

void UART0_IRQHandler(void){
	 interpretCmd_interpretState(GETCHAR());
}


/* ************************************************ */
/* Method name:        main                         */
/* Method description: system entry point           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int main(void)
{
    /* board initializations */
	mcg_clockInit();
	measure_Init();
    timer_coolerfan_init();
    lcd_initLcd();
    debugUart_init();
    buzzer_init();
    tc_installLptmr0(1000000, main_cyclicExecuteIsr);
    //NVIC_EnableIRQ(UART0_IRQn); 						/* habilita interrupcoes de UART0 */
    //UART0_C2_REG(UART0) |= UART0_C2_RIE(1); 			/* habilita interrupcao para RDRF */
    adc_initADCModule();								/* configura ADC*/

    unsigned int uiNovo = 0 , uiAntigo = 0;

    /* cooperative cyclic executive main loop */
    while(1U)
    {
    	/*
    	uiNovo = measure_Cont();
    	measure_String((((uiNovo - uiAntigo)))/7);
    	uiAntigo = uiNovo;*/
        /* WAIT FOR CYCLIC EXECUTIVE PERIOD */


        while(!uiFlagNextPeriod);
    	uiFlagNextPeriod = 0;
    }

    /* Never leave main */
    return 0;
}



