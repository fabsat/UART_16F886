#ifndef _UART_H_
#define _UART_H_


/* Setting Frequency */
#ifndef _XTAL_FREQ
#define _XTAL_FREQ (8000000) //8MHz
#endif


/* Setting Baudrate */
#define BAUDRATE (9600)     // 9.6kbps


/* TXSTA Resister */
#define TXSTA_TX9D  (1 << 0)
#define TXSTA_TRMT  (1 << 1)
#define TXSTA_BRGH  (1 << 2)
#define TXSTA_SENDB (1 << 3)
#define TXSTA_SYNC  (1 << 4)
#define TXSTA_TXEN  (1 << 5)
#define TXSTA_TX9   (1 << 6)
#define TXSTA_CSRC  (1 << 7)


/* RCSTA Resister */
#define RCSTA_RX9D  (1 << 0)
#define RCSTA_OERR  (1 << 1)
#define RCSTA_FERR  (1 << 2)
#define RCSTA_ADDEN (1 << 3)
#define RCSTA_CREN  (1 << 4)
#define RCSTA_SREN  (1 << 5)
#define RCSTA_RX9   (1 << 6)
#define RCSTA_SPEN  (1 << 7)


/* BAUDCTL Resister */
#define BAUDCTL_ABDEN  (1 << 0)
#define BAUDCTL_WUE    (1 << 1)
#define BAUDCTL_BRG16  (1 << 3)
#define BAUDCTL_SCKP   (1 << 4)
#define BAUDCTL_RCIDL  (1 << 6)
#define BAUDCTL_ABDOVF (1 << 7)


/* Setting Baudrate Generator */
#define SPBRG_DATA ((unsigned char)(((_XTAL_FREQ / 16) / BAUDRATE) - 1))


/* Prototype of Function */
void init_uart();
void putch(unsigned char byte);
unsigned char getch();
 
#endif
