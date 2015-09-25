#include <xc.h>
#include <stdio.h>
#include "uart.h"


/* Internal Clock Frequency Set */
#define INT_CLOCK_SET = 0x70


/* Configuratino */
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT        // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF                   // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON                   // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON                   // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF                     // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF                    // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON                   // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF                   // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN =                      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF                    // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

//CONFIG2
#pragma config BOR4V = BOR40V               // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF                    // Flash Program Memory Self Write Enable bits (Write protection off)


/*-----------------------------------------
 * Initialize PIC
 *--------------------------------------*/
void pic_init(void)
{
    PORTA = 0x00;           // Initialize PORTA
    PORTB = 0x00;           // Initialize PORTB
    PORTC = 0x00;           // Initialize PORTC
 
    TRISA = 0b00000000;     
    TRISB = 0b00000000;     
    TRISC = 0b10000000;     // RC7 -> Input  RC6 -> Output
                                
    OSCCON |= INT_CLOCK_SET;  // Oscillator 8MHz
}


/******************************************
 * main Function
 *****************************************/
void main(void)
{
    char data; 

    pic_init();
    init_uart();
     
    printf("Press a key:\r\n");
    
    while(1) {
        data = getch();
        printf("Echo: %c\r\n", data);
    }
}
