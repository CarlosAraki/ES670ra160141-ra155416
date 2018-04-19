#include "debugUart.h"
#include "fsl_debug_console.h"
#include "\Users\aluno\Documents\Jorgito2\ES670\Sources\LEDSWITCH\ledswi_hal.h"
#include "\Users\aluno\Documents\Jorgito2\ES670\Sources\BUZZER\buzzer_hal.h"






char interpretState(char cComando, char cEstado){


	if(cEstado == 'I'){
		switch(cComando){

			case 'L':
					return cComando;
				break;
			case 'S':
					return cComando;
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

