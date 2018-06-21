/* ***************************************************************** */
/* File name:        interpretCmd.c                                  */
/* File description: Interpretador de estados para LED E Switch      */
/* Author name:      Carlos Vinicius Araki Oliveira       RA:160141  */
/*                   Gabriel Bonani Machado               RA:155416  */
/* Creation date:    19abr2018                                       */
/* Revision date:    05jun2018                                       */
/* ***************************************************************** */

#include "debugUart.h"
#include "fsl_debug_console.h"
#include "..\LEDSWITCH\ledswi_hal.h"
#include "..\COOLER\timer_counter.h"
#include "..\BUZZER\buzzer_hal.h"
#include "..\HEATER\heater_hal.h"
#include "interpretCmd.h"




/* ************************************************ */
/* Method name:        interpretState               */
/* Method description: Printa valor no serial       */
/* Input params:       char cComando				*/
/* Output params:      n\a                          */
/* ************************************************ */
void measure_StringSerial(int iCont){
	int cFeature;
			if(0 < iCont/1000){
				cFeature = iCont/1000;
			    PUTCHAR(cFeature+48);

			}
			if(0 < iCont/100){
				cFeature = iCont/100;
				cFeature = cFeature%10;
				PUTCHAR(cFeature+48);
			}
			if(0 < iCont/10){
				cFeature = iCont/10;
				cFeature = cFeature%10;
				PUTCHAR(cFeature+48);
			}
			if(0 < iCont){
				cFeature = iCont%10;
				PUTCHAR(cFeature+48);
			}
			PUTCHAR(' ');
	}



/* ************************************************ */
/* Method name:        interpretState               */
/* Method description: intepreta e executa comandos */
/* dependendo do estado em que se encontra          */
/* Input params:       char cComando				*/
/* Output params:      n\a                     	 	*/
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
					iFlag++;
					cEstado = cComando;
				break;
			case 'H':
					iFlag++;
					cEstado = cComando;
				break;
			case 'M':
				measure_StringSerial(heater_hal_getTemp());
				measure_StringSerial(heater_hal_getRaw());
				PUTCHAR('A');
				PUTCHAR('C');
				PUTCHAR('K');
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
					buzzer_Freq((iValor));
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

	case 'H':
		if(cComando>= '0' && cComando <='9' ){

					if(iFlag == 1){
						if(cComando=='0' || cComando=='1'){
							iValor = (cComando - 48)*100;
								iFlag++;
								cEstado = 'H';
						}
						else{
							PUTCHAR('E');
							PUTCHAR('R');
							PUTCHAR('R');
							(iFlag)= 0;
							cEstado = 'I';
						}
					}

						else if(iFlag == 2){
							iValor = iValor + (cComando - 48)*10;
							iFlag++;
							cEstado = 'H';
						}

						else if((iFlag) == 3){
							(iValor) = (iValor) + (cComando -48);
							(iFlag)= 0;
							cEstado = 'I';
							PUTCHAR('A');
							PUTCHAR('C');
							PUTCHAR('K');
							timer_changeHeaterPwm((iValor));
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
		if(cComando>= '0' && cComando <='9' ){

					if(iFlag == 1){
						if(cComando=='0' || cComando=='1'){
							iValor = (cComando - 48)*100;
								iFlag++;
								cEstado = 'V';
						}
						else{
							PUTCHAR('E');
							PUTCHAR('R');
							PUTCHAR('R');
							(iFlag)= 0;
							cEstado = 'I';
						}
					}

						else if(iFlag == 2){
							iValor = iValor + (cComando - 48)*10;
							iFlag++;
							cEstado = 'V';
						}

						else if((iFlag) == 3){
							iValor = iValor + (cComando -48);
							(iFlag)= 0;
							PUTCHAR('A');
							PUTCHAR('C');
							PUTCHAR('K');
							timer_changeCoolerPwm((iValor));
							iValor = 0;
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





