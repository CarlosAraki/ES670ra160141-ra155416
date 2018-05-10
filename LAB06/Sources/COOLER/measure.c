
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
	 TPM0_SC|=TPM_SC_CMOD(SOP2_SEL);

}


int counter_cont(void){
	int i, a = 0;
	i = (TPM0_CNT<<0x0fu);
	i = (i>>0x0fu);
	return i;
}

void counter_clear(void){

}


void counter_String(int cont){
	int c;

		if(0 < cont/1000){
			c = cont/1000;
		    lcd_setCursor(0,0);
		    lcd_writeData(c+48);
		}
		if(0 < cont/100){
			c = cont/100;
			c = c%10;
		    lcd_setCursor(0,1);
		    lcd_writeData(c+48);
		}
		if(0 < cont/10){
			c = cont/10;
			c = c%10;
		    lcd_setCursor(0,2);
		    lcd_writeData(c + 48);
		}
		if(0 < cont){
			c = cont%10;
		    lcd_setCursor(0,3);
		    lcd_writeData(c+48);
		}
}
