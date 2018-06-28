#include "../PERIPHERAL/es670_peripheral_board.h"
#include "adc.h"


/*****************************/
/*******Variáveis*************/
/*****************************/
static int iTemp  = 0;
static unsigned int suiTemperature = 0;
const unsigned char tabela_temp[256] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,					//15
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,					//31
		1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6,					//47
		7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 10, 10, 11, 11, 12, 12,			//63
		12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17,	//79
		17, 18, 18, 19, 19, 19, 19, 20, 20, 21, 21, 21, 21, 22, 22, 23,	//95
		23, 24, 24, 24, 24, 25, 25, 26, 26, 26, 26, 27, 27, 28, 28, 28,	//111
		28, 29, 29, 30, 30, 30, 30, 31, 31, 32, 32, 32, 32, 33, 33, 34,	//127
		34, 35, 35, 35, 35, 36, 36, 37, 37, 37, 37, 38, 38, 39, 39, 39,	//143
		39, 40, 40, 41, 41, 41, 41, 42, 42, 43, 43, 44, 44, 44, 44, 45,	//159
		45, 46, 46, 46, 46, 47, 47, 48, 48, 48, 48, 49, 49, 50, 50, 50,	//175
		50, 51, 51, 52, 52, 53, 53, 53, 53, 54, 54, 55, 55, 55, 55, 56,	//191
		56, 57, 57, 57, 57, 58, 58, 59, 59, 59, 59, 60, 60, 61, 61, 62,	//207
		62, 62, 62, 63, 63, 64, 64, 64, 64, 65, 65, 66, 66, 66, 66, 67,	//223
		67, 68, 68, 68, 68, 69, 69, 70, 70, 71, 71, 71, 71, 72, 72, 72,	//239
		73, 73, 73, 73, 74, 74, 75, 75, 75, 75, 76, 76, 77, 77, 77, 77	//255
};



/* ************************************************** */
/* Method name: 	 heater_hal_StateMachine          */
/* Method description:  maquina de estados do sensor  */
/*			 de temp		                          */
/* Input params:	   n/a 			                  */
/* Outpu params:	   n/a 			                  */
/* ************************************************** */
void heater_hal_StateMachine(void)
{
	//static int timer se for necessário depois
	static int siEstado = 1;

	switch(siEstado){

	case 1:
		adc_initConvertion();
		siEstado = 2;
		break;

	case 2:
		if(adc_isAdcDone())
		{
			suiTemperature = adc_getConvertionValue();
			siEstado = 3;
		}
		break;

	case 3:
		/*adc_endConvertion*/
		iTemp = tabela_temp[suiTemperature];
		siEstado = 1;
		break;

	}

}

/* ************************************************ */
/* Method name:        heater_hal_getTemp           */
/* Method description: pega valor da temperatura    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

int  heater_hal_getTemp(void)
{
	return iTemp;
}


/* ************************************************ */
/* Method name:        heater_hal_getRaw            */
/* Method description: pega o valor na tabela de    */
/* convercao                                        */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int heater_hal_getRaw(void){

	return suiTemperature;

}
