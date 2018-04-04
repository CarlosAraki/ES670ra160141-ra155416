/* ***************************************************************** */
/* File name:        buzzer_hal.c                                    */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related buzzer from the peripheral board        */
/* Author name:      dloubach                                        */
/* Creation date:    12jan2016                                       */
/* Revision date:    21jan2016                                       */
/* ***************************************************************** */

#include "buzzer_hal.h"
#include "es670_peripheral_board.h"

/* system includes */
#include <MKL25Z4.h>


/* ************************************************ */
/* Method name:        buzzer_init                  */
/* Method description: Initialize the buzzer device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void buzzer_init(void)
{
    /* un-gate port clock */
    SIM_SCGC5 = SIM_SCGC5_PORTD(0x01);

    /* set pin as gpio */
    PORTD_PCR0 = PORT_PCR_MUX(0x01);

    /* set pin as digital output */
    GPIOD_PDDR = GPIO_PDDR_PDD(0x01);

}



/* ************************************************ */
/* Method name:        buzzer_clearBuzz             */
/* Method description: Clear the buzzer             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void buzzer_clearBuzz(void)
{
    /* clear desired pin */
    GPIOD_PCOR = GPIO_PCOR_PTCO(0x01);

}



/* ************************************************ */
/* Method name:        buzzer_setBuzz               */
/* Method description: Set the buzzer               */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void buzzer_setBuzz(void)
{
    /* set desired pin */
    GPIOD_PSOR = GPIO_PSOR_PTSO(0x01);

}
