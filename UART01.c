#include <xc.h>
#include <stdio.h>

#include "UART01.h"

void initUART()
{
    SPBRG = SPBRG_DATA;
    TXSTA = ( TXSTA_TXEN | TXSTA_BRGH);
    RCSTA = ( RCSTA_SPEN | RCSTA_CREN);
}

void putch(unsigned char byte)
{
    while(!TXIF){
    }
    TXREG = byte;
}
 
unsigned char getch()
{
    while(!RCIF){
    }

    return RCREG;
}

unsigned char getche()
{
    unsigned char c;

    c = getch();
    putch(c);

    return c;
}

