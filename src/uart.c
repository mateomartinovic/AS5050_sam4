#include "sam4e16e.h"

#define UART_ID     ID_UART1
#define UARTx       UART1

void uart_init(void) {
    // Enable clock for PIOB (UART1 uses PB4/TX, PB5/RX)
    PMC->PMC_PCER1 = (1 << (UART_ID - 32));

    // Disable PIO control on PB4, PB5 and set peripheral A function
    PIOB->PIO_PDR = PIO_PDR_P4 | PIO_PDR_P5; // Disable PIO    

    // Reset and disable receiver and transmitter
    UARTx->UART_CR = UART_CR_RSTRX | UART_CR_RSTTX | UART_CR_RXDIS | UART_CR_TXDIS;

    // Set baud rate (115200 @ 84 MHz)
    UARTx->UART_BRGR = 45; // 84000000 / (16 * 115200) = 45.14

    // No parity
    UARTx->UART_MR = UART_MR_PAR_NO;

    // Enable receiver and transmitter
    UARTx->UART_CR = UART_CR_RXEN | UART_CR_TXEN;
}

void uart_write_char(char c) {
    while (!(UARTx->UART_SR & UART_SR_TXRDY));  // Wait for TX ready
    UARTx->UART_THR = c;
}

void uart_write_string(const char *str) {
    while (*str) {
        uart_write_char(*str++);
    }
}
