# Quiet Orbit QO-R1 Subsystem Architecture

## System block diagram in prose

A USB-C receptacle accepts nominal 5 V VBUS as a power-only sink. Independent 5.1 kΩ resistors terminate CC1 and CC2 to GND; D+ and D− remain unconnected and no Power Delivery controller is present. VBUS passes through a load-sized resettable fuse and a reverse-current blocking element to create protected VCC. Receptacle-side capacitance is limited to 10 µF nominal, while protected VCC has at least 1 µF of bulk capacitance and a 100 nF ceramic capacitor at the MCU supply pins. Protected VCC powers an ATtiny84A and four resistor-limited amber LED channels. The MCU runs from its internal 8 MHz RC oscillator and independently modulates the four LEDs using four hardware-PWM-capable outputs. A 2 × 3 AVR ISP header connects programming signals, RESET, GND, and a protected-VCC sense connection; it is not a permitted power input. Test points expose VBUS, protected VCC, GND, and RESET. All circuitry is placed on the top side of a two-layer, 1.6 mm PCB within the defined mechanical envelope.

The steady-state architecture allocates at most 20 mA to the four LEDs and at most 20 mA to the MCU and all other non-LED circuitry. The expected design ceiling is therefore 40 mA, with more than 60 mA margin to the strict requirement that USB input current remain below 100 mA in every operating mode. Rationale: a simple direct-5-V architecture meets the product function without a regulator, USB data circuitry, or other avoidable loads.

## USB-C power entry

The connector is a USB-C receptacle configured only as a 5 V sink. CC1 and CC2 each receive their own 5.1 kΩ pull-down to GND so either plug orientation is detected correctly. D+ and D− are intentionally left unconnected, and neither a PD controller nor any higher-voltage negotiation circuitry is included. Rationale: the product needs power only and is constrained to nominal 5 V VBUS.

The receptacle is centred on one board edge and mechanically flush with that edge. The top silkscreen near it reads “USB-C 5V ONLY.” Rationale: this satisfies the enclosure interface and makes the allowed supply unmistakable.

## Input protection

VBUS first passes through a resettable PTC with a nominal 100 mA hold rating and at least 200 mA trip rating at 25 °C, subject to tolerance and thermal-derating review. A series reverse-current blocking element then generates protected VCC and must limit leakage back toward an unpowered VBUS pin to no more than 10 µA at room temperature when protected VCC is driven to 5 V. Rationale: the fuse provides fault discrimination while the blocking element prevents a programmer or sensed header voltage from back-powering the USB port.

Total nominal capacitance directly presented at the receptacle remains no greater than 10 µF. At least 1 µF of bulk capacitance is placed after the protection path, and a separate 100 nF ceramic capacitor is placed directly at the MCU supply pins. Rationale: this balances USB hot-plug inrush with local transient support and high-frequency decoupling.

Final component selection must demonstrate operation across the normal USB 5 V range, keep all protection and passive leakage inside the 20 mA non-LED allocation, satisfy the 10 µA reverse-leakage limit, and be orderable from a major distributor. Rationale: nominal function alone is insufficient unless worst-case electrical limits and sourcing also close.

## MCU + clock

The controller is a Microchip ATtiny84A in SOIC-14, powered directly from protected VCC with no regulator. It uses the internal 8 MHz RC oscillator, so no crystal, resonator, or oscillator load components are fitted. RESET is pulled up to protected VCC with 10 kΩ. Rationale: the specified MCU and internal clock provide the required control with minimal parts and current.

Four distinct MCU outputs must each provide hardware PWM for the four simultaneous independent fades. The final pin map is deliberately deferred until the ATtiny84A reset, ISP, timer-output, alternate-function, and strapping tables have been checked together. ISP-shared outputs may be used only after showing that the fitted LED and resistor loads do not prevent reliable programming. Rationale: this prevents an apparently convenient assignment from breaking PWM or factory programming.

The MCU plus protection and all other non-LED circuitry must remain at or below the assumed 20 mA normal-operation allocation. Rationale: preserving this allocation keeps the complete expected steady-state load at or below 40 mA.

## Light-output user interface

The only user interface is four discrete warm-amber LEDs named NW, NE, SE, and SW as viewed from the component side. Each LED has a dominant wavelength from 590 nm through 605 nm, uses a 1206 or similarly hand-reworkable package, and has its own series resistor and dedicated hardware-PWM drive. Rationale: independent channels create the four-phase fade effect while retaining factory reworkability.

Each channel targets 4 mA nominal at 5 V and must remain within 2–5 mA at full brightness over the selected LED forward-voltage and resistor tolerances. The four channels together must never exceed 20 mA. Final resistor values are therefore selected only after the production LED’s forward-voltage limits are known. Rationale: calculating from tolerance limits protects both the optical requirement and the power budget.

The four optical centres occupy the corners of a 40 mm × 40 mm square centred on the PCB. Rationale: optical centres, rather than footprint origins, must align with the enclosure windows. There are intentionally no buttons, display, audio, radio, or other user controls. Rationale: those functions are outside product scope and would add load and complexity.

## Programming connectivity

Factory programming uses a standard 2 × 3 position, 2.54 mm AVR ISP header with pin 1 identified on top silkscreen. The header carries the required AVR ISP signals, RESET, GND, and protected VCC sense. The product is powered from USB while programming; the ISP VCC contact is voltage sense only and is not an allowed power input. Rationale: this maintains standard tool compatibility without creating a back-power path.

RESET retains its 10 kΩ pull-up during programming. Any LED channels sharing ISP signals must use resistor-limited loads proven compatible with the programmer when all production parts are fitted. Rationale: factory programming is an acceptance requirement, not an optional debug feature.

## Test access

Separate test points expose the exact nets VBUS, protected VCC, GND, and RESET, and top silkscreen labels each with that exact net name. Each test point provides a probeable pad at least 1.0 mm in its smallest dimension with at least 0.5 mm unobstructed clearance around it. Rationale: these nodes permit direct verification of input power, protected power, reference ground, reset behaviour, and reverse isolation using manual probes.

## PCB and mechanical interface

The architecture assumes a 70 mm × 70 mm square PCB, remaining within the absolute 72 mm × 72 mm maximum and the 80 mm × 80 mm × 25 mm enclosure. It uses two copper layers, 1.6 mm finished thickness, minimum 0.20 mm track width, minimum 0.20 mm copper clearance, minimum 0.30 mm finished via drill, and minimum 0.60 mm via diameter. Rationale: these conservative rules preserve broad low-cost fabrication compatibility.

Exactly four M3 non-plated mounting holes use 3.2 mm finished drills. Each hole centre is 4 mm from both adjacent board edges, and the surrounding keepout must preserve mechanical clearance. All components are on the top side. Rationale: this matches the enclosure hardware and factory-assembly constraint.

Top silkscreen includes “QUIET ORBIT / QO-R1,” “USB-C 5V ONLY,” ISP pin 1 identification, and the four required test-point net names. Rationale: these markings support product identity, safe power connection, programming, and test.

## Budget and verification closure

The four LEDs consume no more than 20 mA combined, and the MCU plus every protection, termination, and leakage path consumes no more than 20 mA in normal operation. Thus the expected maximum steady-state load is 40 mA, and every operating mode must remain strictly below 100 mA from USB. Rationale: these nested limits retain explicit margin and guide component selection before schematic capture.

Schematic capture must verify the real ATtiny84A pin functions, four hardware-PWM outputs, ISP compatibility, component quiescent and leakage currents, LED current tolerance, reverse leakage, and capacitor placement. PCB implementation must verify connector alignment, LED optical-centre coordinates, mounting-hole geometry and keepouts, top-side assembly, stack-up, design rules, markings, and test-point access. ERC and PCB DRC must pass before design acceptance. Rationale: architecture values become complete only when traced into implementation and verified against the source files.
