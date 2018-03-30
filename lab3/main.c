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

/* ************************************************ */
/*File name:        main.c					        */
/*File description: gera onda com per�odo de 100ms  */
/* 					Duty Cycle de 10%				*/
/* Author name:  	Carlos Vin�cius Araki Oliveira  */
/* 					RA:160141						*/
/* 					Gabriel Bonani Machado			*/
/* 					RA:15416                        */
/* Creation date:   12/03/2018                      */
/* ************************************************ */

#include "fsl_device_registers.h"
#include "buzzer_hal.h"
#include "mcg_hal.h"
#include "util.h"
#include "ledswi_hal.h"
#include "es670_peripheral_board.h"
#include "7seg_hal.h"
static int i = 0;


int main(void)
{
	mcg_clockInit();// inicializa o clock
	char LedNum = 0, SwitchNum = 4;


/*-----------------------Lab1---------------------------------
    /* Write your code here

	buzzer_init();
    /* This for loop should be replaced. By default this loop allows a single stepping.
    for (;;) {
    	/*
    	 * implementacao da frequencia e do dutycicle da buzzer
    	buzzer_setBuzz();
    	util_genDelay10ms();
    	buzzer_clearBuzz();
    	util_genDelay10ms();
    	util_genDelay10ms();
    	util_genDelay10ms();
		util_genDelay10ms();
		util_genDelay10ms();
		util_genDelay10ms();
		util_genDelay10ms();
		util_genDelay10ms();
		util_genDelay10ms();
        i++;
    }
    /* Never leave main

 -------------------------------------------------------------*/

/*-----------------------Lab2---------------------------------*/
/*	for(;;){
		ledswi_initLedSwitch(0, 4);
		util_genDelay10ms();
		if(SWITCH_ON == ledswi_getSwitchStatus(4)){
			ledswi_initLedSwitch(4, 0);
			ledswi_setLed(4);
		}
		else{
			ledswi_initLedSwitch(4, 0);
			ledswi_clearLed(4);
		}
		util_genDelay10ms();
	}
	return 0;*/
	seg_init();
	clear_Seg();
	for(;;){

			set_Seg(1,1,1);
		}
		return 0;

}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////