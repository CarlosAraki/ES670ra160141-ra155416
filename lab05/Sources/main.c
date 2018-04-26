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
/* Revision date:    26abr2018                                       */
/* ***************************************************************** */

#include "fsl_device_registers.h"
#include "PERIPHERAL/es670_peripheral_board.h"
#include "SERIAL/mcg_hal.h"
#include "SERIAL/debugUart.h"
#include "SERIAL/interpretCmd.h"
#include "UTIL/util.h"
#include "fsl_debug_console.h"
#include "LEDSWITCH/ledswi_hal.h"
#include "BUZZER/buzzer_hal.h"
#include "SEVENSEGMENTS/sevenSegments_hal.h"
#include "LCD/lcd_hal.h"



int main(void)
{
	/* inicializa o clock*/
    mcg_clockInit();

    lcd_initLcd();

    char cCadastro1[] = "Gabriel 155416", cCadastro2[] = "Carlos  160141";
    
    lcd_sendCommand(CMD_CLEAR);
	while(1){

		/* set the cursor line 0, column 0 */
		lcd_setCursor(0,0);

		/* send string */
		lcd_writeString(cCadastro1);

		/* set the cursor line 1, column 0 */
		lcd_setCursor(1,0);
		lcd_writeString(cCadastro2);



	}
    return 0;
    
}


