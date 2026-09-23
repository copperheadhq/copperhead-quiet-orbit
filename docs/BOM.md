# Quiet Orbit QO-R1 Bill of Materials

Every purchasable MPN below is **UNVERIFIED** pending review of the current manufacturer datasheet, distributor stock, lifecycle status, and footprint drawing before release. Each rationale states the properties to verify. Value entries contain schematic component values only.

| Refdes | Value | Footprint | MPN | Rationale |
|---|---|---|---|---|
| J1 | USB-C | Connector_USB:USB_C_Receptacle_GCT_USB4105-xx-A_16P_TopMnt_Horizontal | USB4105-GF-A (UNVERIFIED) | Power-only 16-pin receptacle; verify VBUS, GND, CC, shell, edge-flush geometry, rating, and footprint. Installed `Connector:USB_C_Receptacle_USB2.0_16P` is one unit with confirmed A/B package pins and SH. |
| F1 | 100mA | Fuse:Fuse_0603_1608Metric | MF-FSMF010X-2 (UNVERIFIED) | Verify 100 mA hold, at least 200 mA trip at 25 °C, voltage, resistance, tolerance, derating, and footprint. No quiescent current beyond series loss. Installed `Device:Polyfuse` has pins 1 and 2. |
| D1 | 1N4148W | Diode_SMD:D_SOD-123 | 1N4148W-7-F (UNVERIFIED) | Silicon reverse blocker; verify no more than 10 µA reverse leakage at room temperature and 5 V, no more than 0.8 V forward drop near 20 mA, rating, polarity, and package. Installed diode mapping uses pin 1 K and pin 2 A. |
| C1 | 1uF | Capacitor_SMD:C_0603_1608Metric | CC0603KRX7R9BB105 (UNVERIFIED) | Verify capacitance, X7R dielectric, rating, tolerance, DC-bias loss, leakage, and footprint. The 1 µF receptacle-side value is below the 10 µF limit. |
| C2 | 4.7uF | Capacitor_SMD:C_0805_2012Metric | GRM21BR71A475KA73L (UNVERIFIED) | Verify X7R, at least 10 V rating, tolerance, leakage, footprint, and more than 1 µF retained capacitance at operating bias. |
| C3 | 100nF | Capacitor_SMD:C_0603_1608Metric | CC0603KRX7R9BB104 (UNVERIFIED) | MCU bypass; verify X7R, rating, tolerance, leakage, and footprint; place directly at U1 VCC/GND. |
| R1 | 5.1k | Resistor_SMD:R_0603_1608Metric | RC0603FR-075K1L (UNVERIFIED) | Independent CC1 Rd; verify value, 1% tolerance, rating, and footprint. Worst-case draw is about 1.03 mA at 5.25 V and -1% tolerance. |
| R2 | 5.1k | Resistor_SMD:R_0603_1608Metric | RC0603FR-075K1L (UNVERIFIED) | Independent CC2 Rd; verify value, 1% tolerance, rating, and footprint. Worst-case draw is about 1.03 mA. |
| R3 | 10k | Resistor_SMD:R_0603_1608Metric | RC0603FR-0710KL (UNVERIFIED) | RESET pull-up; verify value, 1% tolerance, rating, and footprint. Normal draw is negligible; RESET-low draw is at most about 0.525 mA. |
| U1 | ATtiny84A | Package_SO:SOIC-14_3.9x8.7mm_P1.27mm | ATTINY84A-SSUR (UNVERIFIED) | Verify 5 V operation, 8 MHz internal RC, supply-current maximum, PWM/ISP functions, lifecycle, and SOIC-14 drawing. Installed one-unit `MCU_Microchip_ATtiny:ATtiny84A-P` has the compatible 14-pin numbering: VCC 1, RESET/PB3 4, PA7..PA0 6..13, GND 14. Budget reserves 10 mA pending datasheet confirmation. |
| D2 | Amber LED | LED_SMD:LED_1206_3216Metric | 150120AS75000 (UNVERIFIED) | NW LED; verify 590–605 nm, forward-voltage bounds at 2–5 mA, optical consistency, polarity, and 1206 package. Installed `Device:LED` uses pin 1 K and pin 2 A. |
| D3 | Amber LED | LED_SMD:LED_1206_3216Metric | 150120AS75000 (UNVERIFIED) | NE LED; same datasheet checks as D2. |
| D4 | Amber LED | LED_SMD:LED_1206_3216Metric | 150120AS75000 (UNVERIFIED) | SE LED; same datasheet checks as D2. |
| D5 | Amber LED | LED_SMD:LED_1206_3216Metric | 150120AS75000 (UNVERIFIED) | SW LED; same datasheet checks as D2. |
| R4 | 680 | Resistor_SMD:R_0603_1608Metric | RC0603FR-07680RL (UNVERIFIED) | NW LED resistor; verify value, 1% tolerance, rating, and footprint. With 4.75–5.25 V VBUS, 0.5–0.8 V D1 drop, 1.8–2.4 V LED drop, and resistor tolerance, current is about 2.26–4.38 mA; repeat using verified limits. |
| R5 | 680 | Resistor_SMD:R_0603_1608Metric | RC0603FR-07680RL (UNVERIFIED) | NE LED resistor; same provisional 2.26–4.38 mA calculation and checks as R4. |
| R6 | 680 | Resistor_SMD:R_0603_1608Metric | RC0603FR-07680RL (UNVERIFIED) | SE LED resistor; same provisional 2.26–4.38 mA calculation and checks as R4. |
| R7 | 680 | Resistor_SMD:R_0603_1608Metric | RC0603FR-07680RL (UNVERIFIED) | SW LED resistor; same provisional 2.26–4.38 mA calculation and checks as R4. |
| J2 | AVR-ISP-6 | Connector_IDC:IDC-Header_2x03_P2.54mm_Vertical | 61200621621 (UNVERIFIED) | Verify 2 × 3 positions, 2.54 mm pitch, numbering, key, height, footprint, and pin-1 marking. Installed `Connector_Generic:Conn_02x03_Odd_Even` is one unit with pins 1–6. VCC is sense-only. |
| TP1 | VBUS | TestPoint:TestPoint_Pad_D1.5mm | DNP | Bare PCB pad; no purchased MPN. Installed `Connector:TestPoint` has pin 1. The 1.5 mm pad exceeds the 1.0 mm minimum; preserve 0.5 mm clearance. |
| TP2 | VCC | TestPoint:TestPoint_Pad_D1.5mm | DNP | Bare protected-VCC PCB pad; same symbol and mechanical checks as TP1. |
| TP3 | GND | TestPoint:TestPoint_Pad_D1.5mm | DNP | Bare GND PCB pad; same symbol and mechanical checks as TP1. |
| TP4 | RESET | TestPoint:TestPoint_Pad_D1.5mm | DNP | Bare RESET PCB pad; same symbol and mechanical checks as TP1. |

## Electrical budget closure

- CC termination worst case is approximately 2.06 mA total.
- U1 reserves 10 mA pending datasheet confirmation. Allowing another 1 mA for all passive leakage and margin gives a provisional 13.06 mA non-LED total, below 20 mA.
- Four LED channels at the provisional 4.38 mA maximum total 17.52 mA, below 20 mA.
- The provisional expected maximum is 30.58 mA, below the 40 mA ceiling and strict 100 mA USB limit. Final release requires replacing every UNVERIFIED check with current datasheet and distributor evidence.
- D1 is the intentional reverse-current element; its exact maximum leakage at 5 V and room temperature must be confirmed as no more than 10 µA.

## Symbol and capture notes

Installed-library searches and pin inspections were completed for U1, J1, J2, D1, D2–D5, F1, and TP1–TP4. All selected symbols are single-unit. Resistors and capacitors use standard `Device:R` and `Device:C`. J1 D+, D−, SBU1, and SBU2 are intentionally unconnected because the product is power-only.
