#include <xc.h>
#include <stdio.h>
 
#include "UART01.h"

#define CLOCK_SET = 0x70

// 16F886
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT        // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

//CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

 
void main(void)
{
    char work;
 
    PORTA = 0x00;           // PORTA????
    PORTB = 0x00;           // PORTB????
 
    TRISA = 0b00000000;     // PORTA??????
    TRISB = 0b00000000;     // PORTB??????
    TRISC = 0b10000000;     // RC7??
                            // RC6??
    
    OSCCON = (OSCCON | CLOCK_SET);
 
    
    initUART();             // ????????????
     
    printf("Press a key:\r\n");
    while(1){
        work = getch();
        printf("Echo: %c\r\n", work);
    }
}