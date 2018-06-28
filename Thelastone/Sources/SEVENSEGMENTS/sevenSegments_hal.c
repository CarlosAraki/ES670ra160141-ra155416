/* ***************************************************************** */
/* File name:        sevenSegments_hal.c                             */
/* File description: funcoes relacionadas ao 7 segmentos             */
/* Author name:      Carlos Vinicius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    26/03/2018                                      */
/* Revision date:    ----------                                      */
/* ***************************************************************** */

#include "sevenSegments_hal.h"
#include "../PERIPHERAL/es670_peripheral_board.h"

/* ************************************************ */
/* Method name:        segInit7Seg                  */
/* Method description: Initialize the segments and  */
/* the displays                                     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void sevenSegments_segInit7Seg(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTC(CGC_CLOCK_ENABLED);
    
    /* set pin as gpio */
    
    /*set the segments*/
    PORTC_PCR0 = PORT_PCR_MUX(SEGA_ALT);
    PORTC_PCR1 = PORT_PCR_MUX(SEGB_ALT);
    PORTC_PCR2 = PORT_PCR_MUX(SEGC_ALT);
    PORTC_PCR3 = PORT_PCR_MUX(SEGD_ALT);
    PORTC_PCR4 = PORT_PCR_MUX(SEGE_ALT);
    PORTC_PCR5 = PORT_PCR_MUX(SEGF_ALT);
    PORTC_PCR6 = PORT_PCR_MUX(SEGG_ALT);
    PORTC_PCR7 = PORT_PCR_MUX(SEGH_ALT);
    
    /*set the displays*/
    PORTC_PCR10 = PORT_PCR_MUX(SEG1_ALT);
    PORTC_PCR11 = PORT_PCR_MUX(SEG2_ALT);
    PORTC_PCR12 = PORT_PCR_MUX(SEG3_ALT);
    PORTC_PCR13 = PORT_PCR_MUX(SEG4_ALT);
    
    /* set pin as digital output */
    GPIOC_PDDR |= GPIO_PDDR_PDD(SEG1_DIR_OUTPUT | SEG2_DIR_OUTPUT | SEG3_DIR_OUTPUT | SEG4_DIR_OUTPUT | SEGA_DIR_OUTPUT | SEGB_DIR_OUTPUT | SEGC_DIR_OUTPUT | SEGD_DIR_OUTPUT | SEGE_DIR_OUTPUT | SEGF_DIR_OUTPUT | SEGG_DIR_OUTPUT | SEGH_DIR_OUTPUT);
    
}


/*if the following functions were called in right order on main, in the 7 seg need to be write HELLO */


/* ************************************************ */
/* Method name:        setSegPin                    */
/* Method description: this function Write a in pin */
/* Input params:       vector unsigned bits         */
/* Output params:      n/a                          */
/* ************************************************ */

void  sevenSegments_setSegPin(char cPin)
{
	GPIOC_PSOR = GPIO_PSOR_PTSO( 0x01U << SEGH_PIN ) ;
    switch(cPin){
        case 1:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x06U << SEGA_PIN ) ;
        break;
        case 2:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x5BU << SEGA_PIN ) ;
        break;
        case 3:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x4FU << SEGA_PIN ) ;
        break;
        case 4:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x66U << SEGA_PIN ) ;
        break;
        case 5:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x6DU << SEGA_PIN ) ;
        break;
        case 6:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x7DU << SEGA_PIN ) ;
        break;
        case 7:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x07U << SEGA_PIN ) ;
        break;
        case 8:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x7FU << SEGA_PIN ) ;
        break;
        case 9:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x6FU << SEGA_PIN ) ;
        break;
    }
    
}

/* ************************************************ */
/* Method name:        setSegDisplay                */
/* Method description: this function Write in       */
/*    selected Disp                                 */
/* Input params:       char selected                */
/* Output params:      n/a                          */
/* ************************************************ */

void  sevenSegments_setSegDisplay(char cSelected)
{
    switch(cSelected){
        case 1:GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << SEG1_PIN) );
            break;
        case 2:GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << SEG2_PIN) );
            break;
        case 3:GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << SEG3_PIN) );
            break;
        case 4:GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << SEG4_PIN) );
            break;
    }
}

/* ************************************************ */
/* Method name:        clearSeg                     */
/* Method description: this function clear the      */
/* display                                          */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */


void  sevenSegments_clearSeg(void)
{
	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEG1_PIN) );
	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEG2_PIN) );
	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEG3_PIN) );
	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEG4_PIN) );
    GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEGA_PIN) );
    GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEGB_PIN) );
    GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEGC_PIN) );
    GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEGD_PIN) );
    GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEGE_PIN) );
    GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEGF_PIN) );
    GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEGG_PIN) );
    GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << SEGH_PIN) );
}


/* ************************************************ */
/* Method name:        setSeg                       */
/* Method description: this function write char c   */
/* in Display selected                              */
/* Input params:       char C                       */
/* Output params:      n/a                          */
/* ************************************************ */

void  sevenSegments_setSeg(char cPin,char cSelected)
{
    sevenSegments_setSegPin(cPin);
    sevenSegments_setSegDisplay(cSelected);
}
