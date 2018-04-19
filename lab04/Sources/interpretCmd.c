#include "debugUart.h"
#include "fsl_debug_console.h"
#include "\Users\aluno\Documents\Jorgito2\ES670\Sources\LEDSWITCH\ledswi_hal.h"
#include "\Users\aluno\Documents\Jorgito2\ES670\Sources\BUZZER\buzzer_hal.h"

void error(void){
	PUTCHAR('E');
	PUTCHAR('R');
	PUTCHAR('R');

}

void ack(void){

	PUTCHAR('A');
	PUTCHAR('C');
	PUTCHAR('K');
}




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
				error();
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
				error();
				return 'I';
		}
	}


	if(cEstado == 'A'){
		if(cComando <= '4' && cComando >= '1'){
			ack();
			ledswi_initLedSwitch(4, 0);
			ledswi_setLed(cComando-48);
			return 'I';
		}
		else{
			error();
			return 'I';
		}

	}


	else if(cEstado == 'C'){
			if(cComando <= '4' && cComando >= '1'){
				ack();
				ledswi_initLedSwitch(4, 0);
				ledswi_clearLed(cComando-48);
				return 'I';
			}
			else{
				error();
				return 'I';
			}

	}


	else if(cEstado == 'S'){
				if(cComando <= '4' && cComando >= '1'){
					ack();
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
					error();
					return 'I';
				}

	}

	return 'I';

}

