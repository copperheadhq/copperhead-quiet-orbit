# Quiet Orbit QO-R1 Pinout

This table is authoritative for schematic-stage signal assignment. Every unused signal pin is explicitly marked NC in `schematic.intent.json`.

| Ref | Pin | Net | Function | Rationale |
|---|---:|---|---|---|
| U1 | 1 | VCC | Protected 5 V supply | Direct protected-VBUS architecture requires no regulator. |
| U1 | 2 | NC | PB0 / XTAL1 unused | Internal 8 MHz RC clock eliminates an external clock connection. |
| U1 | 3 | NC | PB1 / XTAL2 unused | Internal 8 MHz RC clock eliminates an external clock connection. |
| U1 | 4 | RESET | Active-low reset / PB3 | Dedicated reset supports reliable AVR ISP. |
| U1 | 5 | LED_NW | PB2 / OC0A hardware PWM | Dedicated PWM sinks the NW LED channel. |
| U1 | 6 | LED_NE | PA7 / OC0B hardware PWM | Dedicated PWM sinks the NE LED channel. |
| U1 | 7 | ISP_MO_SE | PA6 / MOSI / OC1A hardware PWM | MOSI is shared with the SE LED through its 680 ohm fitted load, which limits loading during ISP. |
| U1 | 8 | ISP_MI_SW | PA5 / MISO / OC1B hardware PWM | MISO is shared with the SW LED through its 680 ohm fitted load, which limits loading during ISP. |
| U1 | 9 | ISP_SCK | PA4 / SCK | Dedicated ISP clock avoids an LED load on SCK. |
| U1 | 10 | NC | PA3 unused | No additional function is required. |
| U1 | 11 | NC | PA2 unused | No additional function is required. |
| U1 | 12 | NC | PA1 unused | No additional function is required. |
| U1 | 13 | NC | PA0 / AREF unused | ADC and external reference are outside scope. |
| U1 | 14 | GND | Ground | MCU supply return. |
| J2 | 1 | ISP_MI_SW | AVR ISP MISO | Shared only through a resistor-limited LED load. |
| J2 | 2 | VCC | Programmer voltage sense | Sense-only; the product must be powered from USB. |
| J2 | 3 | ISP_SCK | AVR ISP SCK | Dedicated clock connection. |
| J2 | 4 | ISP_MO_SE | AVR ISP MOSI | Shared only through a resistor-limited LED load. |
| J2 | 5 | RESET | AVR ISP reset | Connected to U1 reset and the 10 kOhm pull-up. |
| J2 | 6 | GND | Ground | Programmer reference return. |
| J1 | A4,A9,B4,B9 | VBUS | USB 5 V input | All receptacle VBUS contacts are joined. |
| J1 | A5 | USB_CC1 | CC1 sink detect | Independent 5.1 kOhm pull-down through R1. |
| J1 | B5 | USB_CC2 | CC2 sink detect | Independent 5.1 kOhm pull-down through R2. |
| J1 | A1,A12,B1,B12,SH | GND | Ground and shield | Shell is tied to board ground in this revision. |
| J1 | A6,A7,A8,B6,B7,B8 | NC | USB data and SBU unused | Power-only product; data and alternate modes are intentionally absent. |

## LED channel mapping

| Position | LED | Resistor | MCU pin | PWM output | Shared ISP signal |
|---|---|---|---:|---|---|
| NW | D2 | R4 | U1.5 | OC0A | None |
| NE | D3 | R5 | U1.6 | OC0B | None |
| SE | D4 | R6 | U1.7 | OC1A | MOSI |
| SW | D5 | R7 | U1.8 | OC1B | MISO |
