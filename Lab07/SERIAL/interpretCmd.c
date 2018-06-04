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
#include "..\COOLER/timer_counter.h"


/* ************************************************ */
/* Method name:        interpretState               */
/* Method description: intepreta e executa comandos */
/* dependendo do estado em que se encontra          */
/* Input params:       char cComando,char cEstado   */
/* Output params:      char                         */
/* ************************************************ */

char interpretCmd_interpretState(char cComando, char cEstado){


	if(cEstado == 'I'){
		switch(cComando){

			case 'L':
					return cComando;
				break;
			case 'S':
					return cComando;
				break;
			case 'V':
					return cComando;
			default:
				PUTCHAR('E');
				PUTCHAR('R');
				PUTCHAR('R');
				return 'I';
		}
	}

	else if(cEstado == 'V'){
		switch(cComando){
			case '1':
				timer_initTPM1AsPWM(0);
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
				return 'I';
				break;
			case '2':
				 timer_initTPM1AsPWM(25);
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
				return 'I';
				break;
			case '3':
				 timer_initTPM1AsPWM(50);
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
				return 'I';
				break;
			case '4':
				 timer_initTPM1AsPWM(75);
				 PUTCHAR('A');
				 PUTCHAR('C');
				 PUTCHAR('K');

				return 'I';
				break;
			case '5':
				timer_initTPM1AsPWM(100);
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
				return 'I';
				break;
			default:
				PUTCHAR('E');
				PUTCHAR('R');
				PUTCHAR('R');
				return 'I';
		}
	}

	else if(cEstado == 'L'){
		switch(cComando){
			case 'C':
				return cComando;
				break;
			case 'S':
				return 'A';
				break;
			default:
				PUTCHAR('E');
				PUTCHAR('R');
				PUTCHAR('R');
				return 'I';
		}
	}


	if(cEstado == 'A'){
		if(cComando <= '4' && cComando >= '1'){
			PUTCHAR('A');
			PUTCHAR('C');
			PUTCHAR('K');
			ledswi_initLedSwitch(4, 0);
			ledswi_setLed(cComando-48);
			return 'I';
		}
		else{
			PUTCHAR('E');
			PUTCHAR('R');
			PUTCHAR('R');
			return 'I';
		}

	}


	else if(cEstado == 'C'){
			if(cComando <= '4' && cComando >= '1'){
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
				ledswi_initLedSwitch(4, 0);
				ledswi_clearLed(cComando-48);
				return 'I';
			}
			else{
				PUTCHAR('E');
				PUTCHAR('R');
				PUTCHAR('R');
				return 'I';
			}

	}


	else if(cEstado == 'S'){
				if(cComando <= '4' && cComando >= '1'){
					PUTCHAR('A');
					PUTCHAR('C');
					PUTCHAR('K');
					ledswi_initLedSwitch(0, 4);
					if(SWITCH_ON == ledswi_getSwitchStatus(cComando-48)){
						PUTCHAR('O');
						PUTCHAR('N');
						return 'I';

					}
					else{
						PUTCHAR('O');
						PUTCHAR('F');
						PUTCHAR('F');
						return 'I';

					}
				}

				else{
					PUTCHAR('E');
					PUTCHAR('R');
					PUTCHAR('R');
					return 'I';
				}

	}

	return 'I';

}

