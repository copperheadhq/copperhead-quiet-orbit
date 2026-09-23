#ifndef QO_R1_PINS_H
#define QO_R1_PINS_H

#include <avr/io.h>

/* Generated from docs/PINOUT.md; do not assign board pins elsewhere. */
#define QO_MCU_PART                 ATtiny84A
#define QO_CPU_HZ                   8000000UL

/* U1.5: PB2 / OC0A, net LED_NW. */
#define LED_NW_DDR                  DDRB
#define LED_NW_PORT                 PORTB
#define LED_NW_BIT                  PB2
#define LED_NW_OCR                  OCR0A

/* U1.6: PA7 / OC0B, net LED_NE. */
#define LED_NE_DDR                  DDRA
#define LED_NE_PORT                 PORTA
#define LED_NE_BIT                  PA7
#define LED_NE_OCR                  OCR0B

/* U1.7: PA6 / MOSI / OC1A, net ISP_MO_SE. */
#define LED_SE_DDR                  DDRA
#define LED_SE_PORT                 PORTA
#define LED_SE_BIT                  PA6
#define LED_SE_OCR                  OCR1A
#define ISP_MOSI_DDR                DDRA
#define ISP_MOSI_PORT               PORTA
#define ISP_MOSI_BIT                PA6

/* U1.8: PA5 / MISO / OC1B, net ISP_MI_SW. */
#define LED_SW_DDR                  DDRA
#define LED_SW_PORT                 PORTA
#define LED_SW_BIT                  PA5
#define LED_SW_OCR                  OCR1B
#define ISP_MISO_DDR                DDRA
#define ISP_MISO_PORT               PORTA
#define ISP_MISO_BIT                PA5

/* U1.9: PA4 / SCK, net ISP_SCK. */
#define ISP_SCK_DDR                 DDRA
#define ISP_SCK_PORT                PORTA
#define ISP_SCK_BIT                 PA4

/* U1.4: PB3 / RESET, net RESET; fuse-controlled reset input. */
#define RESET_DDR                   DDRB
#define RESET_PORT                  PORTB
#define RESET_BIT                   PB3

/* U1.2, U1.3, U1.10-U1.13 are NC by design. */

#endif
