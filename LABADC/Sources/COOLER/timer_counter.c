/* ***************************************************************** */
/* File name:        timer_counter.c                                 */
/* File description: cooler metodos para pwm                         */
/* Author name:      Carlos Vinicius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    05jun2018                                       */
/* Revision date:    ----------                                      */
/* ***************************************************************** */


#include "../PERIPHERAL/es670_peripheral_board.h"
#include "fsl_tpm_hal.h"

/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 		              */
/* ************************************************** */
void timer_initTPM1AsPWM(void)
{
	/* un-gate port clock*/
	int freqcore = 8000000;
	int prescale = 1;
	int freqpwm = 400;
	SIM_SCGC6 |=SIM_SCGC6_TPM1(CGC_CLOCK_ENABLED);
	TPM1_SC |= TPM_SC_CPWMS(0x00u);   //up counting mode 0
	TPM1_SC |= TPM_SC_CMOD(0x01u);   //LPTPM Counter increments on every LPTPM counter clock 01
	TPM1_SC |= TPM_SC_PS(0x000u);   //Prescale 1:1 00
	TPM1_C1SC |= TPM_CnSC_MSB(0x01u)|TPM_CnSC_MSA(0x00u)|TPM_CnSC_ELSB(0x01u)|TPM_CnSC_ELSA(0x00u) ;
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(SOP2_SEL);
	TPM1_CNT = TPM_CNT_COUNT(0x00u);
	TPM1_MOD = TPM_MOD_MOD((freqcore*(1/prescale))/(freqpwm));
	TPM1_C0SC |= (TPM_CnSC_MSB(0b1) | TPM_CnSC_MSA(0b0) | TPM_CnSC_ELSB(0b1) | TPM_CnSC_ELSA(0b0));



}

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_coolerfan_init(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    /* set pin as PWM */
    PORTA_PCR13 |= PORT_PCR_MUX(0x03u);

}



/* ************************************************ */
/* Method name:        timer_changeHeaterPwm        */
/* Method description: pwm in heater device         */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_changeHeaterPwm(int iPwm)
{
	iPwm = (iPwm)*TPM1_MOD/100;
	TPM1_C0V = TPM_CnV_VAL(iPwm);
}


/* ************************************************ */
/* Method name:        timer_changeCoolerPwm        */
/* Method description: pwm in cooler device 		*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void timer_changeCoolerPwm(int i)
{

	TPM1_C1V = TPM_CnV_VAL(i*TPM1_MOD/(100));
}



/* ************************************************ */
/* Method name:        timer_initHeater	            */
/* Method description: Initialize the heater device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_initHeater(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    /* set pin as PWM */
    PORTA_PCR12 |= PORT_PCR_MUX(0x03u);
}


