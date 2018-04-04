/* ***************************************************************** */
/* File name:         es670_peripheral_board.h                       */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    21jan2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_ES670_PERIPHERAL_BOARD_H_
#define SOURCES_ES670_PERIPHERAL_BOARD_H_


/*                 BUZZER Definitions                    */
#define BUZZER_PORT_BASE_PNT    PORTD                                /* peripheral port base pointer */
#define BUZZER_GPIO_BASE_PNT    PTD                                  /* peripheral gpio base pointer */

#define BUZZER_PIN                0U                                 /* buzzer pin */
#define BUZZER_DIR                kGpioDigitalOutput
#define BUZZER_ALT                kPortMuxAsGpio
/*                 END OF BUZZER definitions             */


#endif /* SOURCES_ES670_PERIPHERAL_BOARD_H_ */
