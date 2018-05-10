/* ***************************************************************** */
/* File name:        cooler_hal.h                                    */
/* File description: cooler metodos                                  */
/* Author name:      Carlos Vinicius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    26mar2018                                       */
/* Revision date:    ----------                                      */
/* ***************************************************************** */
#include "cooler_hal.h"
#include "../PERIPHERAL/es670_peripheral_board.h"

void cooler_Init(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    /* set pin as gpio */

    PORTA_PCR13 = PORT_PCR_MUX(COOLER_ALT);

    /* set pin as digital output */
    GPIOA_PDDR |= GPIO_PDDR_PDD(COOLER_DIR);

}


void cooler_SetPin(void)
{
	GPIOA_PSOR = GPIO_PSOR_PTSO(0x01u << COOLER_PIN);
}

void cooler_ClearPin(void)
{
	GPIOA_PCOR = GPIO_PCOR_PTCO(0x01u << COOLER_PIN);
}
