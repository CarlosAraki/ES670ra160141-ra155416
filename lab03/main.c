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

/* **************************************************/
/*File name:        main.c                          */
/*File description:  								*/
/* Author name:      Carlos VinÃ­cius Araki Oliveira */
/*                     RA:160141                    */
/*                     Gabriel Bonani Machado       */
/*                     RA:15416                     */
/* Creation date:   12/03/2018                      */
/* ************************************************ */

#include "fsl_device_registers.h"
#include "es670_peripheral_board.h"
#include "mcg_hal.h"
#include "util.h"
#include "\Users\aluno\Documents\Jorgito2\ES670\Sources\LEDSWITCH\ledswi_hal.h"
#include "\Users\aluno\Documents\Jorgito2\ES670\Sources\BUZZER\buzzer_hal.h"
#include "\Users\aluno\Documents\Jorgito2\ES670\Sources\SEVENSEGMENTS\sevenSegments_hal.h"



int main(void)
{
	/* inicializa o clock*/
    mcg_clockInit();

	buzzer_init();
	sevenSegments_segInit7Seg();
	sevenSegments_clearSeg();
    
    /*-----------------------Lab1---------------------------------*/


     /* This for loop should be replaced. By default this loop allows a single stepping.*/
    /* implementacao da frequencia e do dutycicle da buzzer*/

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


    /*-----------------------Lab2---------------------------------*/

     for(;;){
    	 ledswi_initLedSwitch(0, 4);
		 if(SWITCH_ON == ledswi_getSwitchStatus(4)){
			 ledswi_initLedSwitch(4, 0);
			 ledswi_setLed(4);
			 ledswi_clearLed(3);
			 ledswi_clearLed(2);
			 ledswi_clearLed(1);
		 }
		 else if(SWITCH_ON == ledswi_getSwitchStatus(3)){
			 ledswi_initLedSwitch(4, 0);
			 ledswi_setLed(3);
			 ledswi_clearLed(4);
			 ledswi_clearLed(2);
			 ledswi_clearLed(1);
		 }
		 else if(SWITCH_ON == ledswi_getSwitchStatus(2)){
			 ledswi_initLedSwitch(4, 0);
			 ledswi_setLed(2);
			 ledswi_clearLed(3);
			 ledswi_clearLed(4);
			 ledswi_clearLed(1);
		 }
		 else if(SWITCH_ON == ledswi_getSwitchStatus(1)){
			 ledswi_initLedSwitch(4, 0);
			 ledswi_setLed(1);
			 ledswi_clearLed(3);
			 ledswi_clearLed(2);
			 ledswi_clearLed(4);
		 }
		 else{
			 ledswi_initLedSwitch(4, 0);
			 ledswi_clearLed(4);
			 ledswi_clearLed(3);
			 ledswi_clearLed(2);
			 ledswi_clearLed(1);
		 }
    	sevenSegments_setSeg(1,1);
        util_genDelay1ms();
        sevenSegments_clearSeg();

        sevenSegments_setSeg(2,2);
		util_genDelay1ms();
		sevenSegments_clearSeg();

		sevenSegments_setSeg(5,3);
		util_genDelay1ms();
		sevenSegments_clearSeg();

		sevenSegments_setSeg(6,4);
		util_genDelay1ms();
		sevenSegments_clearSeg();

    }
    return 0;
    
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
