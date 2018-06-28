/********************************************************/
/*File name:		 measure.c			*/
/*File description: 	measure metodos			*/
/*Author name: 		CarlosAraki & Gabriel Bonani	*/
/*Creation date:	16mai2018			*/
/*Revision date:	22mai2018			*/
/********************************************************/

#include "measure.h"
#include "../PERIPHERAL/es670_peripheral_board.h"
#include "../LCD/lcd_hal.h"


/* ************************************************ */
/* Method name:        measure_Init                 */
/* Method description:Initialize TPM0 and tachometer*/
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void measure_Init(void){
	/*un-gate clock TPM*/

	SIM_SCGC6 |= SIM_SCGC6_TPM0(CGC_CLOCK_ENABLED);

	/*un-gate clock PTE29*/
	SIM_SCGC5 |= SIM_SCGC5_PORTE(CGC_CLOCK_ENABLED);
	/*Alternate 4 para clkin0 */
	PORTE_PCR29 |= PORT_PCR_MUX(TACOMETRO_ALT);

	/*selecionar para external clock*/
	SIM_SOPT4 |= SIM_SOPT4_TPM0CLKSEL(SOP4_SEL);
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(SOP2_SEL);

	/*configuração do tpm,ps,etc*/
	TPM0_SC |=TPM_SC_PS(SOP4_SEL);
	TPM0_SC |=TPM_SC_CMOD(SOP2_SEL);

}

/* ************************************************ */
/* Method name:        measure_Cont                 */
/* Method description: Return TPM0_CNT Value        */
/* function  										*/
/* Input params:       n/a                          */
/* Output params:      int  iCont                   */
/* ************************************************ */
int measure_Cont(void){
	int iCont;
	iCont = TPM0_CNT;
	TPM0_CNT = 0;
	return iCont;
}

/* ************************************************ */
/* Method name:        measure_Strin               */
/* Method description:Transform int iCont in LCD     */
/* string                                           */
/* function  										*/
/* Input params:       int iCont                     */
/* Output params:      n/a                          */
/* ************************************************ */
void measure_String(int iCont){
	int cFeature;

		if(0 <= iCont/1000){
			cFeature = iCont/1000;
		    lcd_setCursor(0,0);
		    lcd_writeData(cFeature+48);
		}
		if(0 <= iCont/100){
			cFeature = iCont/100;
			cFeature = cFeature%10;
		    lcd_setCursor(0,1);
		    lcd_writeData(cFeature+48);
		}
		if(0 <= iCont/10){
			cFeature = iCont/10;
			cFeature = cFeature%10;
		    lcd_setCursor(0,2);
		    lcd_writeData(cFeature + 48);
		}
		if(0 <= iCont){
			cFeature = iCont%10;
		    lcd_setCursor(0,3);
		    lcd_writeData(cFeature+48);
		}
}


unsigned int measure_Dif()
	{
	static int uiNovo = 0 , uiAntigo = 0,uiBuffer=0;
	static unsigned int uiTime = 0;
	//uiTime++;
	//if(uiTime == 1){
		uiNovo = measure_Cont();
		uiBuffer = (uiNovo -uiAntigo)/7;
		uiAntigo = uiNovo;
		uiTime = 0;
	//}


	return uiBuffer;

}

