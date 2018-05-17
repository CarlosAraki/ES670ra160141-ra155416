
#include "measure.h"
#include "../PERIPHERAL/es670_peripheral_board.h"
#include "../LCD/lcd_hal.h"

void counter_init(void){
	/*un-gate clock TPM*/

	SIM_SCGC6 |= SIM_SCGC6_TPM0(CGC_CLOCK_ENABLED);

	/*un-gate clock PTE29*/
	SIM_SCGC5 |= SIM_SCGC5_PORTE(CGC_CLOCK_ENABLED);
	PORTE_PCR29 = PORT_PCR_MUX(TACOMETRO_ALT);

	SIM_SOPT4 = SIM_SOPT4_TPM0CLKSEL(SOP4_SEL);
	SIM_SOPT2 = SIM_SOPT2_TPMSRC(SOP2_SEL);
	TPM0_SC |=TPM_SC_PS(SOP4_SEL);
	TPM0_SC |=TPM_SC_CMOD(SOP2_SEL);

}


int counter_cont(void){
	int iCont;
	iCont = (TPM0_CNT<<0x0fu);
	iCont = (iCont>>0x0fu);
	return iCont;
}


void counter_String(int iCont){
	int cFeature;

		if(0 < iCont/1000){
			cFeature = iCont/1000;
		    lcd_setCursor(0,0);
		    lcd_writeData(cFeature+48);
		}
		if(0 < iCont/100){
			cFeature = iCont/100;
			cFeature = cFeature%10;
		    lcd_setCursor(0,1);
		    lcd_writeData(cFeature+48);
		}
		if(0 < iCont/10){
			cFeature = iCont/10;
			cFeature = cFeature%10;
		    lcd_setCursor(0,2);
		    lcd_writeData(cFeature + 48);
		}
		if(0 < iCont){
			cFeature = iCont%10;
		    lcd_setCursor(0,3);
		    lcd_writeData(cFeature+48);
		}
}
