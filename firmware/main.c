#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "led_pwm.h"
#include "pins.h"

#if F_CPU != QO_CPU_HZ
#error "F_CPU must match the 8 MHz internal-RC requirement in docs/PINOUT.md"
#endif

static uint8_t triangle(uint8_t phase)
{
    return (phase & 0x80U) ? (uint8_t)(255U - ((phase & 0x7fU) << 1))
                           : (uint8_t)((phase & 0x7fU) << 1);
}

int main(void)
{
    uint8_t phase = 0U;

    led_pwm_init();

    for (;;) {
        /* Happy path: four independent fades, separated by quarter cycles. */
        led_pwm_set(LED_NW, triangle(phase));
        led_pwm_set(LED_NE, triangle((uint8_t)(phase + 64U)));
        led_pwm_set(LED_SE, triangle((uint8_t)(phase + 128U)));
        led_pwm_set(LED_SW, triangle((uint8_t)(phase + 192U)));
        ++phase;
        _delay_ms(4);
    }
}
