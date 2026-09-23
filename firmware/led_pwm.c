#include "led_pwm.h"
#include "pins.h"

static uint8_t compare_for_sink_brightness(uint8_t brightness)
{
    /* LEDs are fed from VCC and sink into the MCU; low output means on. */
    return (uint8_t)(255U - brightness);
}

void led_pwm_init(void)
{
    LED_NW_DDR |= _BV(LED_NW_BIT);
    LED_NE_DDR |= _BV(LED_NE_BIT);
    LED_SE_DDR |= _BV(LED_SE_BIT);
    LED_SW_DDR |= _BV(LED_SW_BIT);

    led_pwm_all_off();

    /* Timer 0: fast PWM, non-inverting OC0A/OC0B, clk/64. */
    TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
    TCCR0B = _BV(CS01) | _BV(CS00);

    /* Timer 1: 8-bit fast PWM, non-inverting OC1A/OC1B, clk/64. */
    TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);
    TCCR1B = _BV(WGM12) | _BV(CS11) | _BV(CS10);
}

void led_pwm_set(led_channel_t channel, uint8_t brightness)
{
    const uint8_t compare = compare_for_sink_brightness(brightness);

    switch (channel) {
    case LED_NW: LED_NW_OCR = compare; break;
    case LED_NE: LED_NE_OCR = compare; break;
    case LED_SE: LED_SE_OCR = compare; break;
    case LED_SW: LED_SW_OCR = compare; break;
    default: break;
    }
}

void led_pwm_all_off(void)
{
    LED_NW_OCR = 255U;
    LED_NE_OCR = 255U;
    LED_SE_OCR = 255U;
    LED_SW_OCR = 255U;
}
