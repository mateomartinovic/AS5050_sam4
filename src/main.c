#include "sam4e16e.h"

#define LED_PORT PIOA
#define LED_PIN  22    // PA23 — user LED on SAM4E Xplained Pro

void delay(volatile uint32_t count) {
    while (count--) __asm__("nop");
}

int main(void) {
    // Enable clock to PIOA
    PMC->PMC_PCER0 = (1 << ID_PIOA);

    // Configure PA23 as output
    LED_PORT->PIO_PER = (1 << LED_PIN);  // Enable PIO control
    LED_PORT->PIO_OER = (1 << LED_PIN);  // Output enable
    LED_PORT->PIO_SODR = (1 << LED_PIN); // Set high (LED off)

    while (1) {
        // Toggle LED
        LED_PORT->PIO_CODR = (1 << LED_PIN);  // Clear pin (LED ON)
        delay(1000000);
        LED_PORT->PIO_SODR = (1 << LED_PIN);  // Set pin (LED OFF)
        delay(1000000);
    }
}
