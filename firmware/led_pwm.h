#ifndef QO_R1_LED_PWM_H
#define QO_R1_LED_PWM_H

#include <stdint.h>

typedef enum {
    LED_NW = 0,
    LED_NE,
    LED_SE,
    LED_SW,
    LED_COUNT
} led_channel_t;

void led_pwm_init(void);
void led_pwm_set(led_channel_t channel, uint8_t brightness);
void led_pwm_all_off(void);

#endif
