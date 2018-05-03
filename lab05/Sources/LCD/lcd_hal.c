/* ***************************************************************** */
/* File name:        lcd_hal.c                                       */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the LCD hardware from   */
/*                   the hardware kit                                */
/* Author name:      CarlosAraki/gabmac/dloubach                     */
/* Creation date:    16out2015                                       */
/* Revision date:    03mai2018                                       */
/* ***************************************************************** */

#include "lcd_hal.h"
#include "../PERIPHERAL/es670_peripheral_board.h"
#include "../UTIL/util.h"



/* line and columns */
#define LINE0        0U
#define COLUMN0      0U

#define L0C0_BASE    0x80 /* line 0, column 0 */
#define L1C0_BASE    0xC0 /* line 1, column 0 */
#define MAX_COLUMN  15U

/* ************************************************ */
/* Method name:        lcd_initLcd                  */
/* Method description: Initialize the LCD function  */
/* Input params:       n/a                          */
/* Output params:       n/a                         */
/* ************************************************ */
void lcd_initLcd(void)
{
    /* pins configured as outputs */

    /* un-gate port clock*/
	SIM_SCGC5 |= SIM_SCGC5_PORTC(CGC_CLOCK_ENABLED);

    /* set pin as gpio */
    PORTC_PCR0 = PORT_PCR_MUX(LCD_DATA_ALT);
    PORTC_PCR1 = PORT_PCR_MUX(LCD_DATA_ALT);
    PORTC_PCR2 = PORT_PCR_MUX(LCD_DATA_ALT);
    PORTC_PCR3 = PORT_PCR_MUX(LCD_DATA_ALT);
    PORTC_PCR4 = PORT_PCR_MUX(LCD_DATA_ALT);
    PORTC_PCR5 = PORT_PCR_MUX(LCD_DATA_ALT);
    PORTC_PCR6 = PORT_PCR_MUX(LCD_DATA_ALT);
    PORTC_PCR7 = PORT_PCR_MUX(LCD_DATA_ALT);

    /*set the displays*/
    PORTC_PCR8 = PORT_PCR_MUX(LCD_RS_ALT);
    PORTC_PCR9 = PORT_PCR_MUX(LCD_ENABLE_ALT);

    /* set pin as digital output */
    GPIOC_PDDR |= GPIO_PDDR_PDD(LCD_RS_DIR|LCD_ENABLE_DIR|LCD_DATA_DB0_DIR|LCD_DATA_DB1_DIR|LCD_DATA_DB2_DIR|LCD_DATA_DB3_DIR|LCD_DATA_DB4_DIR|LCD_DATA_DB5_DIR|LCD_DATA_DB6_DIR|LCD_DATA_DB7_DIR);
    // turn-on LCD, with no cursor and no blink
    lcd_sendCommand(CMD_NO_CUR_NO_BLINK);

    // init LCD
    lcd_sendCommand(CMD_INIT_LCD);

    // clear LCD
    lcd_sendCommand(CMD_CLEAR);

    // LCD with no cursor
    lcd_sendCommand(CMD_NO_CURSOR);

    // cursor shift to right
    lcd_sendCommand(CMD_CURSOR2R);

}



/* ************************************************ */
/* Method name:        lcd_write2Lcd                */
/* Method description: Send command or data to LCD  */
/* Input params:       ucBuffer => char to be send  */
/*                     cDataType=>command LCD_RS_CMD*/
/*                     or data LCD_RS_DATA          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_write2Lcd(unsigned char ucBuffer,  unsigned char cDataType)
{
    /* writing data or command */
    if(LCD_RS_CMD == cDataType){
        /* will send a command */
    	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << LCD_RS_PIN) );
    }
    else{
        /* will send data */
    	GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << LCD_RS_PIN) );
    }

    /* write in the LCD bus */

    if (0 != ((ucBuffer & (1u << 0u)) >> 0u))
        {
    		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << LCD_DATA_DB0_PIN) );
        }

        else
        {
        	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << LCD_DATA_DB0_PIN) );
        }

    if (0 != ((ucBuffer & (1u << 1u)) >> 1u))
        {
    		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << LCD_DATA_DB1_PIN) );
        }

        else
        {
        	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << LCD_DATA_DB1_PIN) );
        }

    if (0 != ((ucBuffer & (1u << 2u)) >> 2u))
        {
    		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << LCD_DATA_DB2_PIN) );
        }

        else
        {
        	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << LCD_DATA_DB2_PIN) );;
        }

    if (0 != ((ucBuffer & (1u << 3u)) >> 3u))
        {
    		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << LCD_DATA_DB3_PIN) );
        }

        else
        {
        	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << LCD_DATA_DB3_PIN) );
        }

    if (0 != ((ucBuffer & (1u << 4u)) >> 4u))
        {
    		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << LCD_DATA_DB4_PIN) );
        }

        else
        {
        	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << LCD_DATA_DB4_PIN) );
        }

    if (0 != ((ucBuffer & (1u << 5u)) >> 5u))
        {
    		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << LCD_DATA_DB5_PIN) );
        }

        else
        {
        	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << LCD_DATA_DB5_PIN) );
        }

    if (0 != ((ucBuffer & (1u << 6u)) >> 6u))
        {
    		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << LCD_DATA_DB6_PIN) );
        }

        else
        {
        	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << LCD_DATA_DB6_PIN) );
        }
    if (0 != ((ucBuffer & (1u << 7u)) >> 7u))
        {
    		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << LCD_DATA_DB7_PIN) );
        }
        else
        {
        	GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << LCD_DATA_DB7_PIN) );
        }


    /* enable, delay, disable LCD */
    /* this generates a pulse in the enable pin */
    GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << LCD_ENABLE_PIN) );
    util_genDelay1ms();
    GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << LCD_ENABLE_PIN) );
    util_genDelay1ms();
    util_genDelay1ms();
}



/* ************************************************ */
/* Method name:        lcd_writeData                */
/* Method description: Write data to be displayed   */
/* Input params:       ucData => char to be written */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeData(unsigned char ucData)
{
    /* just a relay to send data */
    lcd_write2Lcd(ucData, LCD_RS_DATA);
}



/* ************************************************ */
/* Method name:        lcd_sendCommand              */
/* Method description: Write command to LCD         */
/* Input params:       ucCmd=>command to be executed*/
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_sendCommand(unsigned char ucCmd)
{
    /* just a relay to send command */
    lcd_write2Lcd(ucCmd, LCD_RS_CMD);
}



/* ************************************************ */
/* Method name:        lcd_setCursor                */
/* Method description: Set cursor line and column   */
/* Input params:       cLine = LINE0..LINE1         */
/*                     cColumn = COLUMN0..MAX_COLUMN*/
/* Output params:       n/a                         */
/* ************************************************ */
void lcd_setCursor(unsigned char cLine, unsigned char cColumn)
{
    char cCommand;

    if(LINE0 == cLine)
        /* line 0 */
        cCommand = L0C0_BASE;
    else
        /* line 1 */
        cCommand = L1C0_BASE;

    /* maximum MAX_COLUMN columns */
    cCommand += (cColumn & MAX_COLUMN);

    // send the command to set the cursor
    lcd_sendCommand(cCommand);
}



/* ************************************************ */
/* Method name:        lcd_writeString              */
/* Method description: Write string to be displayed */
/* Input params:       cBuffer => string to be      */
/*                     written in LCD               */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeString(const char *cBuffer)
{
    while(*cBuffer)
    {
        lcd_writeData(*cBuffer++);
    };
}



/* ************************************************ */
/* Method name:        lcd_dummyText                */
/* Method description: Write a dummy hard coded text*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_dummyText(void)
{
    // clear LCD
    lcd_sendCommand(CMD_CLEAR);

    // set the cursor line 0, column 1
    lcd_setCursor(0,1);

    // send string
    lcd_writeString("*** ES670 ***");

    // set the cursor line 1, column 0
    lcd_setCursor(1,0);
    lcd_writeString("Prj Sis Embarcad");
}
