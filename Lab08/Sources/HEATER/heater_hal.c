#include "../PERIPHERAL/es670_peripheral_board.h"
#include "adc.h"
#include "lut_adc_3v3.c" //Copiar depois pq não dá certo mesmo com ifdef


/*****************************/
/*******Variáveis*************/
/*****************************/
struct Data
{
	unsigned int  uiBoolean = 0;
	int iTemp = 0; //inicializada com temp zero
}stData;



/* ************************************************** */
/* Method name: 	 heater_hal_StateMachine      */
/* Method description:  maquina de estados do sensor  */
/*			 de temp		      */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 			      */
/* ************************************************** */
void heater_hal_StateMachine(void)
{
	//static int timer se for necessário depois
	static int siEstado = 1;
	static unsigned int suiTemperature = 0;

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
		uiTempCelsius = tabela_temp[suiTemperature];
		siEstado = 1;
		stData.iTemp =  uiTempCelsius;
		break;

	}

}

/* ************************************************** */
/* Method name: 	 heater_hal_getTemp	      */
/* Method description:  retorna o valor conv na temp  */
/* Input params:	   n/a 			      */
/* Outpu params:	   int iTemp		      */
/* ************************************************** */

int  heater_hal_getTemp()
{
	return stData.iTemp;
}	
//Criar struct de dados 
//Criar get_heater_hal
