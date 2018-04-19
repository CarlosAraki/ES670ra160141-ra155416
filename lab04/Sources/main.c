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
#include "debugUart.h"
#include "util.h"
#include "fsl_debug_console.h"
#include "LEDSWITCH/ledswi_hal.h"
#include "\Users\aluno\Documents\Jorgito2\ES670\Sources\BUZZER\buzzer_hal.h"
#include "\Users\aluno\Documents\Jorgito2\ES670\Sources\SEVENSEGMENTS\sevenSegments_hal.h"
#include "interpretCmd.h"


int main(void)
{
	/* inicializa o clock*/
    mcg_clockInit();

	/*sevenSegments_segInit7Seg();
	sevenSegments_clearSeg();*/
    debugUart_init();
    buzzer_init();
    

    char cComando,cEstado = 'I',cValue;
    int iFlag = 0,iValor = 0;

	while(1){

		if(UART0_BRD_S1_RDRF(UART0)){

				cComando = GETCHAR();
				if(cComando == 'B' || cEstado == 'B'){
					if(iFlag == 0){
						cEstado = cComando;
						iFlag++;
					}
				else if(cComando>= '0' && cComando <='9' ){

					if(iFlag == 1){
							iValor = (cComando - 48)*100;
							iFlag++;
						}

						else if(iFlag == 2){
							iValor = iValor + (cComando - 48)*10;
							iFlag++;

						}

						else if(iFlag == 3){
							iValor = iValor + (cComando -48);
							iFlag = 0;
							cEstado = 'I';
							PUTCHAR('A');
							PUTCHAR('C');
							PUTCHAR('K');
							buzzer_freq(iValor);

						}
				}
					else{
						PUTCHAR('E');
						PUTCHAR('R');
						PUTCHAR('R');
						iFlag = 0;
						cEstado = 'I';
					}
				}
				else{
					cEstado = interpretState(cComando,cEstado);
				}
			}
	}
    return 0;
    
}

