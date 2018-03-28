/* ***************************************************************** */
/* File name:        7seg_hal.c                                    */
/* File description: This file has a couple of useful functions to   */
/*                   control 7seg from peripheral board */
/* Author name:      Carlos Vinícius Araki Oliveira
/*					 Gabriel Bonani Machado                            */
/* Creation date:    26/03/2018                                       */
/* Revision date:    ----------                                      */
/* ***************************************************************** */

#include "7seg_hal.h"
#include "es670_peripheral_board.h"




/* ************************************************ */
/* Method name:        ledswi_initLedSwitch         */
/* Method description:
/* Input params:
/* Output params:      n/a                          */
/* ************************************************ */

void seg_init(void){
	      /* un-gate port clock*/
	      SIM_SCGC5 = SIM_SCGC5_PORTC(CGC_CLOCK_ENABLED);

	      /* set pin as gpio */

	      /*set the segments*/
	     PORTC_PCR0 = PORT_PCR_MUX(SegA_ALT);
	     PORTC_PCR1 = PORT_PCR_MUX(SegB_ALT);
	     PORTC_PCR2 = PORT_PCR_MUX(SegC_ALT);
	     PORTC_PCR3 = PORT_PCR_MUX(SegD_ALT);
	     PORTC_PCR4 = PORT_PCR_MUX(SegE_ALT);
	     PORTC_PCR5 = PORT_PCR_MUX(SegF_ALT);
	     PORTC_PCR6 = PORT_PCR_MUX(SegG_ALT);
	     PORTC_PCR7 = PORT_PCR_MUX(SegH_ALT);

	     /*set the displays*/
	     PORTC_PCR10 = PORT_PCR_MUX(Seg1_ALT);
	     PORTC_PCR11 = PORT_PCR_MUX(Seg2_ALT);
	     PORTC_PCR12 = PORT_PCR_MUX(Seg3_ALT);
	     PORTC_PCR13 = PORT_PCR_MUX(Seg4_ALT);

	      /* set pin as digital output */
	     GPIOC_PDDR |= GPIO_PDDR_PDD(Seg1_DIR_OUTPUT | Seg2_DIR_OUTPUT | Seg3_DIR_OUTPUT | Seg4_DIR_OUTPUT | SegA_DIR_OUTPUT | SegB_DIR_OUTPUT | SegC_DIR_OUTPUT | SegD_DIR_OUTPUT | SegE_DIR_OUTPUT | SegF_DIR_OUTPUT | SegG_DIR_OUTPUT | SegH_DIR_OUTPUT);;

}

void set_Seg(char num, char dot, char display){
		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << SegA_PIN) );
		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << SegB_PIN) );
		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << SegC_PIN) );
		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << SegD_PIN) );
		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << SegE_PIN) );
		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << SegF_PIN) );
		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << Seg1_PIN) );


}
void clear_Seg(){
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SegA_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SegB_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SegC_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SegD_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SegE_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SegF_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SegG_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SegH_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << Seg1_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << Seg2_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << Seg3_PIN) );
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << Seg4_PIN) );

}


