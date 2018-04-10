/* ***************************************************************** */
/* File name:        sevenSegments_hal.c                              */
/* File description: This file has a couple of useful functions to   */
/*                   write "Hello" in 7seg from peripheral board     */
/* Author name:      Carlos Vinícius Araki Oliveira                  */
/*                   Gabriel Bonani Machado                          */
/* Creation date:    26/03/2018                                      */
/* Revision date:    ----------                                      */
/* ***************************************************************** */



/* ************************************************ */
/* Method name:        segInit7Seg                  */
/* Method description: Initialize the segments and  */
/* the displays                                     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

void sevenSegments_segInit7Seg(void);


/* ************************************************ */
/* Method name:        setSegPin                    */
/* Method description: this function Write a in pin */
/* Input params:       vector unsigned bits         */
/* Output params:      n/a                          */
/* ************************************************ */

void  sevenSegments_setSegPin(char c)
{
    switch(c){
        case 1:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x60U << SEGA_PIN ) ;
        break;
        case 2:GPIOC_PSOR = GPIO_PSOR_PTSO( 0xdaU << SEGA_PIN ) ;
        break;
        case 3:GPIOC_PSOR = GPIO_PSOR_PTSO( 0xf2U << SEGA_PIN ) ;
        break;
        case 4:GPIOC_PSOR = GPIO_PSOR_PTSO( 0x66U << SEGA_PIN ) ;
        break;
        case 5:GPIOC_PSOR = GPIO_PSOR_PTSO( 0xb6U << SEGA_PIN ) ;
        break;
        case 6:GPIOC_PSOR = GPIO_PSOR_PTSO( 0xbeU << SEGA_PIN ) ;
        break;
        case 7:GPIOC_PSOR = GPIO_PSOR_PTSO( 0xe2U << SEGA_PIN ) ;
        break;
        case 8:GPIOC_PSOR = GPIO_PSOR_PTSO( 0xfeU << SEGA_PIN ) ;
        break;
        case 9:GPIOC_PSOR = GPIO_PSOR_PTSO( 0xf6U << SEGA_PIN ) ;
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

void  sevenSegments_setSegDisplay(char selected)
{
    switch(selected){
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


void sevenSegments_clearSeg(void);

/* ************************************************ */
/* Method name:        setSeg                     	*/
/* Method description: this function write char c 	*/
/* in Display                                       */
/* Input params:       char C                       */
/* Output params:      n/a                          */
/* ************************************************ */

void sevenSegments_setSeg(char C);
