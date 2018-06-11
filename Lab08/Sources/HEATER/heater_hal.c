#include "../PERIPHERAL/es670_peripheral_board.h"
#include "adc.h"
#include "lut_adc_3v3.c"
/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 			      */
/* ************************************************** */
void heater_hal_StateMachine(void)
{
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
		break;

	}

}
