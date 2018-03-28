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

#define Seg_PORT_BASE_PNT        PORTC                                   /* peripheral port base pointer */
#define Seg_GPIO_BASE_PNT        PTC

#define SegA_PIN                   0U /*The value here come from the pin of the pinout table*/
#define SegA_ALT                   0x01u
#define SegA_DIR_OUTPUT            (GPIO_OUTPUT << SegA_PIN)

#define SegB_PIN                   1U
#define SegB_ALT                   SegA_ALT
#define SegB_DIR_OUTPUT            (GPIO_OUTPUT << SegB_PIN)

#define SegC_PIN                   2U
#define SegC_ALT                   SegA_ALT
#define SegC_DIR_OUTPUT            (GPIO_OUTPUT << SegC_PIN)

#define SegD_PIN                   3U
#define SegD_ALT                   SegA_ALT
#define SegD_DIR_OUTPUT            (GPIO_OUTPUT << SegD_PIN)

#define SegE_PIN                   4U
#define SegE_ALT                   SegA_ALT
#define SegE_DIR_OUTPUT            (GPIO_OUTPUT << SegE_PIN)

#define SegF_PIN                   5U
#define SegF_ALT                   SegA_ALT
#define SegF_DIR_OUTPUT            (GPIO_OUTPUT << SegF_PIN)

#define SegG_PIN                   6U
#define SegG_ALT                   0x01u
#define SegG_DIR_OUTPUT            (GPIO_OUTPUT << SegG_PIN)

#define SegH_PIN                   7U
#define SegH_ALT                   SegA_ALT
#define SegH_DIR_OUTPUT            (GPIO_OUTPUT << SegH_PIN)

/*This part defines the 7Seg display*/

#define Seg1_PIN                   10U
#define Seg1_ALT                   SegA_ALT
#define Seg1_DIR_OUTPUT            (GPIO_OUTPUT << Seg1_PIN)

#define Seg2_PIN                   11U
#define Seg2_ALT                   SegA_ALT
#define Seg2_DIR_OUTPUT            (GPIO_OUTPUT << Seg2_PIN)

#define Seg3_PIN                   12U
#define Seg3_ALT                   SegA_ALT
#define Seg3_DIR_OUTPUT            (GPIO_OUTPUT << Seg3_PIN)

#define Seg4_PIN                   13U
#define Seg4_ALT                   SegA_ALT
#define Seg4_DIR_OUTPUT            (GPIO_OUTPUT << Seg4_PIN)



/*                 END OF 7SEG definitions               */


#endif /* SOURCES_ES670_PERIPHERAL_BOARD_H_ */
