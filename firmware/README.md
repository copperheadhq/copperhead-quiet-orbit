# Firmware

ATtiny84A, AVR-GCC, internal 8 MHz RC oscillator. Four LEDs on the chip's four hardware-PWM
outputs across Timer 0 and Timer 1, driven as a triangle fade with the four channels a quarter
cycle apart.

> This has never been compiled. No AVR toolchain was available where it was written, and it has
> never run on hardware because no hardware exists. If `make` fails, please send a patch.

```bash
make            # -> quiet-orbit-qo-r1.hex, mcu attiny84, F_CPU=8000000UL
```

Needs `avr-gcc` and `avr-libc`. Flash through the ISP header with any AVR programmer.

| File | What |
|---|---|
| `main.c` | the fade loop |
| `led_pwm.c/.h` | timer setup and per-channel brightness |
| `pins.h` | the board pin map, generated from `docs/PINOUT.md` |
| `Makefile` | builds with `-Wall -Wextra -Werror` |

All pin definitions live in `pins.h` and nowhere else, so firmware and schematic cannot drift
apart silently. `main.c` has a compile-time check that `F_CPU` matches the documented clock.

The LEDs are active-low, and two of the four channels share the ISP data lines through their
LED resistors. Expect those two to flicker while programming. A programmer with series
resistance on MOSI may struggle to pull the line low against the 680 Ω LED resistor; 1 kΩ
gives more margin.
