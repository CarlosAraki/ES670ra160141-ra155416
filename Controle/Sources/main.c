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
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT iLimITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT iLimITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
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
#include "HEATER/adc.h"
#include "HEATER/heater_hal.h"
#include "PID/pid.h"



/* system includes */
#include "fsl_debug_console.h"

/* globals */
volatile unsigned int uiFlagNextPeriod = 0;         /* cyclic executive flag */
volatile unsigned int uiTempCelsius = 0;
volatile unsigned int uiFlagIntCom = 0,vuiPonteiro;
volatile char vcBuffer[50],cComand;


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
	uiFlagIntCom = 1;
	cComand = GETCHAR();
	if(vuiPonteiro >50 ){
		vuiPonteiro = 0;
	}
	vcBuffer[vuiPonteiro] = cComand;
	vuiPonteiro++;

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
    tc_installLptmr0(1000000/2, main_cyclicExecuteIsr);
    NVIC_EnableIRQ(UART0_IRQn); 						/* habilita interrupcoes de UART0 */
    UART0_C2_REG(UART0) |= UART0_C2_RIE(1); 			/* habilita interrupcao para RDRF */
    adc_initADCModule();
    /* configura ADC*/
    timer_initTPM1AsPWM();
    timer_initHeater();
    timer_coolerfan_init();
    timer_changeCoolerPwm(0);							/*começa desligado o cooler e o heater pwm*/
    timer_changeHeaterPwm(0);

    unsigned int uiNovo = 0 , uiAntigo = 0;
    int iLim = 0;
    int iCorredor = 0;
    PID_DATA pid_data;
    pid_init(&pid_data);
    /* cooperative cyclic executive main loop */
    while(1U)
    {
    	if(1 == uiFlagIntCom){
    		if(iCorredor < vuiPonteiro){
    			interpretCmd_interpretState(vcBuffer[iCorredor],&pid_data);
    			iCorredor++;
    		}
    		else{
    			iCorredor = 0;
    			vuiPonteiro = 0;
    			uiFlagIntCom = 0;
    		}
    	}

    	uiNovo = measure_Cont();
    	uiNovo = uiNovo*1000000/(7*1000000/2);
    	measure_String(uiNovo);
    	timer_changeCoolerPwm(pid_Control(&pid_data, uiNovo));
    	//measure_String(measure_Dif());
    	heater_hal_StateMachine();
    	iLim = heater_hal_getTemp();
    	//measure_String(iLim);
    	if(iLim > 60){
    		timer_changeHeaterPwm(0);
    	}
        /* WAIT FOR CYCLIC EXECUTIVE PERIOD */
       while(!uiFlagNextPeriod);
    	uiFlagNextPeriod = 0;
    }
    /* Never leave main */
    return 0;
}

