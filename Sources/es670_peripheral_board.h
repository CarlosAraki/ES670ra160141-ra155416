/* ***************************************************************** */
/* File name:        es670_peripheral_board.h                        */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_ES670_PERIPHERAL_BOARD_H_
#define SOURCES_ES670_PERIPHERAL_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/* GPIO input / output */
#define GPIO_INPUT                  0x00U
#define GPIO_OUTPUT                 0x01U


/*                 END OF General uC definitions         */



/*                 BUZZER Definitions                    */
#define BUZZER_PORT_BASE_PNT        PORTD                                   /* peripheral port base pointer */
#define BUZZER_GPIO_BASE_PNT        PTD                                     /* peripheral gpio base pointer */

#define BUZZER_PIN                  1U                                      /* buzzer pin */
#define BUZZER_DIR                  kGpioDigitalOutput
#define BUZZER_ALT                  0x01u
/*                 END OF BUZZER definitions             */


/*                 LED and SWITCH Definitions                    */
#define LS_PORT_BASE_PNT            PORTA                                   /* peripheral port base pointer */
#define LS_GPIO_BASE_PNT            PTA                                     /* peripheral gpio base pointer */

/* THIS PIN CONFLICTS WITH PTA1 USED AS UART0_RX IN THE OPENSDA SERIAL DEBUG PORT */
#define LS1_PIN                     1U                                      /* led/switch #1 pin */
#define LS1_DIR_OUTPUT              (GPIO_OUTPUT << LS1_PIN)
#define LS1_DIR_INPUT               (GPIO_OUTPUT << LS1_PIN)
#define LS1_ALT                     0x01u                                   /* GPIO alternative */

/* THIS PIN CONFLICTS WITH PTA2 USED AS UART0_TX IN THE OPENSDA SERIAL DEBUG PORT */
#define LS2_PIN                     2U                                      /* led/switch #2 pin */
#define LS2_DIR_OUTPUT              (GPIO_OUTPUT << LS2_PIN)
#define LS2_DIR_INPUT               (GPIO_OUTPUT << LS2_PIN)
#define LS2_ALT                     LS1_ALT

#define LS3_PIN                     4U                                      /* led/switch #3 pin */
#define LS3_DIR_OUTPUT              (GPIO_OUTPUT << LS3_PIN)
#define LS3_DIR_INPUT               (GPIO_OUTPUT << LS3_PIN)
#define LS3_ALT                     LS1_ALT

#define LS4_PIN                     5U                                      /* led/switch #4 pin */
#define LS4_DIR_OUTPUT              (GPIO_OUTPUT << LS4_PIN)
#define LS4_DIR_INPUT               (GPIO_OUTPUT << LS4_PIN)
#define LS4_ALT                     LS1_ALT

/*                 END OF LED and SWITCH definitions             */

/*                 7Seg Definition                       */

/*This part defines the segments, based on pinout*/

#define SEG_PORT_BASE_PNT        PORTC                                   /* peripheral port base pointer */
#define SEG_GPIO_BASE_PNT        PTC

#define SEGA_PIN                   0U /*The value here come from the pin of the pinout table*/
#define SEGA_ALT                   0x01u
#define SEGA_DIR_OUTPUT            (GPIO_OUTPUT << SEGA_PIN)

#define SEGB_PIN                   1U
#define SEGB_ALT                   SEGA_ALT
#define SEGB_DIR_OUTPUT            (GPIO_OUTPUT << SEGB_PIN)

#define SEGC_PIN                   2U
#define SEGC_ALT                   SEGA_ALT
#define SEGC_DIR_OUTPUT            (GPIO_OUTPUT << SEGC_PIN)

#define SEGD_PIN                   3U
#define SEGD_ALT                   SEGA_ALT
#define SEGD_DIR_OUTPUT            (GPIO_OUTPUT << SEGD_PIN)

#define SEGE_PIN                   4U
#define SEGE_ALT                   SEGA_ALT
#define SEGE_DIR_OUTPUT            (GPIO_OUTPUT << SEGE_PIN)

#define SEGF_PIN                   5U
#define SEGF_ALT                   SEGA_ALT
#define SEGF_DIR_OUTPUT            (GPIO_OUTPUT << SEGF_PIN)

#define SEGG_PIN                   6U
#define SEGG_ALT                   0x01u
#define SEGG_DIR_OUTPUT            (GPIO_OUTPUT << SEGG_PIN)

#define SEGH_PIN                   7U
#define SEGH_ALT                   SEGA_ALT
#define SEGH_DIR_OUTPUT            (GPIO_OUTPUT << SEGH_PIN)

/*This part defines the 7Seg display*/

#define SEG1_PIN                   10U
#define SEG1_ALT                   SEGA_ALT
#define SEG1_DIR_OUTPUT            (GPIO_OUTPUT << SEG1_PIN)

#define SEG2_PIN                   11U
#define SEG2_ALT                   SEGA_ALT
#define SEG2_DIR_OUTPUT            (GPIO_OUTPUT << SEG2_PIN)

#define SEG3_PIN                   12U
#define SEG3_ALT                   SEGA_ALT
#define SEG3_DIR_OUTPUT            (GPIO_OUTPUT << SEG3_PIN)

#define SEG4_PIN                   13U
#define SEG4_ALT                   SEGA_ALT
#define SEG4_DIR_OUTPUT            (GPIO_OUTPUT << SEG4_PIN)



/*                 END OF 7SEG definitions               */


#endif /* SOURCES_ES670_PERIPHERAL_BOARD_H_ */
