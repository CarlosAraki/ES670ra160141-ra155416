#include "../PERIPHERAL/es670_peripheral_board.h"

/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 			      */
/* ************************************************** */
void timer_initTPM1AsPWM(void)
{
	
    /* Channel 0 Config - Heater */
    TPM1_C0SC |= (TPM_CnSC_MSB(0b1) | TPM_CnSC_MSA(0b0) | TPM_CnSC_ELSB(0b1) | TPM_CnSC_ELSA(0b0));

    TPM1_C0V = 0x00; //PWM 00%
	
    /* COMPLETAR SEU CODIGO COM AS LINHAS ACIMA */

}

/* ************************************************ */
/* Method name:        timer_changeHeaterPwm        */
/* Method description: change the cooler pwm        */
/* Input params:       pwm desired (percentage)     */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_changeHeaterPwm(int iPwm)
{
	iPwm = (iPwm)*TPM1_MOD/100;
	TPM1_C0V = iPwm;
}

/* ************************************************ */
/* Method name:        timer_initHeater             */
/* Method description: Initialize the heater device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_initHeater(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    /* set pin as PWM */
    PORTA_PCR12 |= PORT_PCR_MUX(0x03);
}

