#include <xc.h>
#include <stdio.h>

#include "uart.h"


/*-----------------------------------
 * Initialize uart
 *---------------------------------*/
void uart_init()
{
    SPBRG = SPBRG_DATA;
    TXSTA = (TXSTA_TXEN | TXSTA_BRGH);
    RCSTA = (RCSTA_SPEN | RCSTA_CREN);
}


/*-----------------------------------
 * Transmit 1 byte
 *---------------------------------*/
void putch(unsigned char byte)
{
    while(!TXIF){
        ;        
    }
    
    TXREG = byte;
}


/*-----------------------------------
 * Receive 1 byte
 *---------------------------------*/
unsigned char getch()
{
    while(!RCIF){
        ;        
    }

    return RCREG;
}

