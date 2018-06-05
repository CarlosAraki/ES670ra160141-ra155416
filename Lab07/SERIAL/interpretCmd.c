/* ***************************************************************** */
/* File name:        interpretCmd.c                                  */
/* File description: Interpretador de estados para LED E Switch      */
/* Author name:      Carlos Vinicius Araki Oliveira       RA:160141  */
/*                   Gabriel Bonani Machado               RA:155416  */
/* Creation date:    19abr2018                                       */
/* Revision date:    26abr2018                                       */
/* ***************************************************************** */

#include "debugUart.h"
#include "fsl_debug_console.h"
#include "..\LEDSWITCH\ledswi_hal.h"
#include "..\COOLER\timer_counter.h"
#include "..\BUZZER\buzzer_hal.h"
#include "interpretCmd.h"


/* ************************************************ */
/* Method name:        interpretState               */
/* Method description: intepreta e executa comandos */
/* dependendo do estado em que se encontra          */
/* Input params:       char cComando,char cEstado   */
/* Output params:      char                         */
/* ************************************************ */

void interpretCmd_interpretState(char cComando){

	static int iFlag = 0;
	static int iValor = 0;
	static char cEstado = 'I';

	switch(cEstado){

	case 'I':
		switch(cComando){

			case 'B':
					iFlag++;
					cEstado = cComando;
			case 'L':
					cEstado = cComando;
				break;
			case 'S':
					cEstado = cComando;
				break;
			case 'V':
					cEstado = cComando;
				break;
			default:
				PUTCHAR('E');
				PUTCHAR('R');
				PUTCHAR('R');
				cEstado = 'I';
		}
		break;


	case 'B':

		if(cComando>= '0' && cComando <='9' ){

			if(iFlag == 1){
				iValor = (cComando - 48)*100;
					iFlag++;
					cEstado = 'B';
			}

				else if(iFlag == 2){
					iValor = iValor + (cComando - 48)*10;
					iFlag++;
					cEstado = 'B';
				}

				else if((iFlag) == 3){
					(iValor) = (iValor) + (cComando -48);
					(iFlag)= 0;
					cEstado = 'I';
					PUTCHAR('A');
					PUTCHAR('C');
					PUTCHAR('K');
					buzzer_freq((iValor));
					(iValor) = 0;
					cEstado = 'I';
				}
		}
			else{
				PUTCHAR('E');
				PUTCHAR('R');
				PUTCHAR('R');
				(iFlag)= 0;
				cEstado = 'I';
			}
	break;



	case 'V':
		switch(cComando){
			case '1':
				timer_initTPM1AsPWM(0);
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
				cEstado = 'I';
				break;
			case '2':
				 timer_initTPM1AsPWM(25);
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
				cEstado = 'I';
				break;
			case '3':
				 timer_initTPM1AsPWM(50);
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
				cEstado = 'I';
				break;
			case '4':
				 timer_initTPM1AsPWM(75);
				 PUTCHAR('A');
				 PUTCHAR('C');
				 PUTCHAR('K');

				cEstado = 'I';
				break;
			case '5':
				timer_initTPM1AsPWM(100);
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
				cEstado = 'I';
				break;
			default:
				PUTCHAR('E');
				PUTCHAR('R');
				PUTCHAR('R');
				cEstado = 'I';
		}
	break;

	case 'L':
		switch(cComando){
			case 'C':
				cEstado = cComando;
				break;
			case 'S':
				cEstado = 'A';
				break;
			default:
				PUTCHAR('E');
				PUTCHAR('R');
				PUTCHAR('R');
				cEstado = 'I';
		}
	break;


	case 'A':
		if(cComando <= '4' && cComando >= '1'){
			PUTCHAR('A');
			PUTCHAR('C');
			PUTCHAR('K');
			ledswi_initLedSwitch(4, 0);
			ledswi_setLed(cComando-48);
			cEstado = 'I';
		}
		else{
			PUTCHAR('E');
			PUTCHAR('R');
			PUTCHAR('R');
			cEstado = 'I';
		}

	break;


	case 'C':
			if(cComando <= '4' && cComando >= '1'){
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
				ledswi_initLedSwitch(4, 0);
				ledswi_clearLed(cComando-48);
				cEstado = 'I';
			}
			else{
				PUTCHAR('E');
				PUTCHAR('R');
				PUTCHAR('R');
				cEstado = 'I';
			}

	break;


	case 'S':
				if(cComando <= '4' && cComando >= '1'){
					PUTCHAR('A');
					PUTCHAR('C');
					PUTCHAR('K');
					ledswi_initLedSwitch(0, 4);
					if(SWITCH_ON == ledswi_getSwitchStatus(cComando-48)){
						PUTCHAR('O');
						PUTCHAR('N');
						cEstado = 'I';

					}
					else{
						PUTCHAR('O');
						PUTCHAR('F');
						PUTCHAR('F');
						cEstado = 'I';

					}
				}

				else{
					PUTCHAR('E');
					PUTCHAR('R');
					PUTCHAR('R');
					cEstado = 'I';
				}

	break;

	default:
		cEstado == 'I';
	}

}



