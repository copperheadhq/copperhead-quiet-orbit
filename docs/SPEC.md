# Quiet Orbit QO-R1 Product Specification

## Product

Quiet Orbit QO-R1 is a USB-C-powered desk ornament whose four warm-amber light windows form a 2 × 2 grid and fade independently on four phases. It has no USB data, Power Delivery, radio, battery, buttons, or other user controls. Firmware is programmed once at the factory through AVR ISP.

Requirement words **MUST**, **SHALL**, **SHOULD**, and **MAY** are normative. Items marked **ASSUMED** are defaults introduced because the brief does not specify them and may be revised during design review. Each assumption includes its rationale.

## Top-level budgets and constraints

- Input supply: nominal USB VBUS, 5 V only; the circuit SHALL tolerate the normal USB 5 V supply range. No voltage above 5 V may be requested through PD. (QO-001) Rationale: the product is a fixed 5 V USB sink.
- USB input current: total steady-state current from USB SHALL remain strictly below 100 mA in every operating mode. (QO-010) Rationale: preserves the stated source-current ceiling with any compliant port or charger.
- LED count and optical band: exactly four discrete amber LEDs, each 590–605 nm. (QO-004) Rationale: establishes the intended four-window warm-amber appearance.
- LED full-brightness current: each LED SHALL draw 2–5 mA, inclusive; the four LEDs therefore consume at most 20 mA combined. (QO-004) Rationale: meets the brightness requirement while leaving substantial input-current margin.
- LED geometry: LED optical centres SHALL occupy the corners of a 40 mm × 40 mm square centred on the board. (QO-005) Rationale: fixes alignment with the four enclosure windows.
- Board envelope: the finished PCB SHALL be square and no larger than 72 mm × 72 mm. (QO-008) Rationale: fits the specified 80 mm × 80 mm × 25 mm enclosure.
- Mounting: exactly four M3 non-plated mounting holes, one near each corner, with each hole centre 4 mm from both adjacent board edges. (QO-008) Rationale: matches the stated enclosure mounting geometry.
- Stack-up: two copper layers and 1.6 mm finished thickness using standard fabrication rules. (QO-010) Rationale: meets the cost and manufacturability target.
- Programming connector: 2 × 3 positions on 2.54 mm pitch. (QO-006) Rationale: maintains compatibility with standard AVR ISP cables.
- RESET pull-up: 10 kΩ to protected VCC. (QO-006) Rationale: provides a defined run state while allowing ISP assertion.
- USB-C CC termination: CC1 and CC2 SHALL each have an independent 5.1 kΩ pull-down to GND. (QO-001) Rationale: advertises a sink correctly for both plug orientations and supports C-to-C cables.
- MCU clock: the ATtiny84A SHALL use its internal 8 MHz RC oscillator. (QO-003) Rationale: eliminates the crystal and its load components.

## Functional requirements

### QO-001: USB-C power input

The board SHALL use a USB-C receptacle as a 5 V sink only. CC1 and CC2 SHALL each have their own 5.1 kΩ Rd termination. USB D+ and D− SHALL not be routed or connected, and the design SHALL contain no PD controller or other negotiation circuitry. The receptacle SHALL be centred on one board edge and mechanically flush with that edge.

### QO-002: Input protection and filtering

A resettable fuse SHALL be sized for the load. Reverse-current protection SHALL prevent a programmer or any header voltage from back-feeding the USB VBUS pin. Bulk and local bypass capacitance SHALL support USB hot-plugging and normal transient load steps.

- **ASSUMED:** Use a PTC with 100 mA nominal hold current and at least 200 mA trip current at 25 °C, subject to final tolerance and thermal derating review. Rationale: it passes the allowed load while providing useful fault discrimination.
- **ASSUMED:** Limit receptacle-side input capacitance to 10 µF nominal and place at least 1 µF bulk capacitance after the fuse/protection element. Rationale: provides transient energy without excessive hot-plug inrush.
- **ASSUMED:** Provide one 100 nF ceramic decoupling capacitor directly at the MCU supply pins. Rationale: this is the conventional minimum local high-frequency bypass for the ATtiny84A.
- **ASSUMED:** Reverse leakage from protected VCC toward VBUS SHALL be no more than 10 µA at room temperature when VBUS is unpowered and protected VCC is driven to 5 V. Rationale: makes accidental USB-port back-power negligible and objectively testable.

### QO-003: Controller

The MCU SHALL be a Microchip ATtiny84A in SOIC-14, powered directly from protected 5 V. It SHALL use its internal 8 MHz RC oscillator. No crystal, external oscillator, or regulator SHALL be fitted. MCU pin assignment SHALL be checked against reset, ISP, and alternate-function tables before schematic capture.

### QO-004: Lights and drive

The board SHALL contain four discrete 590–605 nm amber LEDs in 1206 or a similarly hand-reworkable package. Each LED SHALL have its own series resistor and its own MCU pin with a hardware PWM output, permitting four simultaneous independent fades. Full-brightness current SHALL be 2–5 mA per LED.

- **ASSUMED:** Target 4 mA nominal per LED at 5 V; the final resistor SHALL be calculated from the selected LED forward-voltage limits so the full tolerance range remains within 2–5 mA. Rationale: centres brightness within the allowed range and preserves wide current margin.
- ISP-shared LED pins MAY be used only if the fitted LED/resistor networks do not prevent reliable programming. Rationale: pin sharing is explicitly permitted but programming remains mandatory.

### QO-005: LED placement

As viewed from the component side, the four LEDs SHALL be named NW, NE, SE, and SW and placed at the corners of a board-centred 40 mm × 40 mm square. Their optical centres, rather than footprint origins, govern placement.

### QO-006: Factory programming

Provide a standard 2 × 3, 2.54 mm AVR ISP header with pin 1 identified on silkscreen. RESET SHALL have a 10 kΩ pull-up. The product SHALL be powered from USB while programming; the ISP VCC pin SHALL be a voltage-sense connection only and SHALL not be a permitted power input. Programming SHALL work with all LEDs and resistors fitted.

### QO-007: Test access

Provide separately accessible test points for VBUS, protected VCC, GND, and RESET. Each SHALL be labelled on silkscreen with that exact net name.

- **ASSUMED:** Each test point SHALL expose a probeable pad at least 1.0 mm in its smallest dimension with at least 0.5 mm unobstructed clearance around it. Rationale: supports reliable manual factory probing without requiring a custom fixture.

### QO-008: Mechanical construction

The PCB SHALL be square and no larger than 72 mm × 72 mm. It SHALL fit an 80 mm × 80 mm × 25 mm enclosure. Four M3 non-plated mounting holes SHALL be provided, one per corner, with hole centres 4 mm from each adjacent edge. The USB-C receptacle SHALL be centred on one edge and flush with that edge. All components SHALL be on the top side.

- **ASSUMED:** Use a 70 mm × 70 mm board outline. Rationale: provides 1 mm dimensional margin on every side relative to the maximum envelope while retaining useful routing area.
- **ASSUMED:** Use 3.2 mm finished drill diameter for the M3 clearance holes. Rationale: this is a common close-clearance size for M3 hardware.

### QO-009: Marking

Top silkscreen SHALL include “QUIET ORBIT / QO-R1” and “USB-C 5V ONLY” near the receptacle. It SHALL also identify ISP pin 1 and the four required test points.

### QO-010: Fabrication, assembly, and sourcing

The design SHALL use a two-layer, 1.6 mm PCB compatible with standard fabrication rules. All parts SHALL be orderable from major distributors at design release. SMT parts SHALL be factory-assemblable on the top side; the ISP header MAY be through-hole. Total USB current SHALL remain below 100 mA.

- **ASSUMED:** Standard design-rule minima are 0.20 mm copper track width, 0.20 mm copper clearance, 0.30 mm finished via drill, and 0.60 mm via diameter unless the selected fabricator permits no better. Rationale: conservative values are broadly supported by low-cost PCB fabs.
- **ASSUMED:** Every production BOM item SHALL have at least one orderable manufacturer part number from a major distributor and SHOULD have a form-fit-function alternative where practical. Rationale: makes the sourcing requirement reviewable and reduces lifecycle risk.

## Power budget

Worst-case steady-state allocation against the strict <100 mA USB limit:

- Four LEDs: 20 mA maximum total (4 × 5 mA).
- **ASSUMED:** MCU and all non-LED circuitry: maximum 20 mA combined in normal operation. Rationale: this comfortably covers the ATtiny84A at 8 MHz plus passive leakage and leaves explicit margin.
- **ASSUMED:** Design verification ceiling: 40 mA expected maximum steady-state load, leaving more than 60 mA margin to the required limit. Rationale: a 2.5× margin accommodates tolerance and abnormal firmware states while keeping fuse selection practical.

The schematic BOM and component limits SHALL be checked against both the 40 mA expected ceiling and the absolute requirement of less than 100 mA.

## Scope exclusions

Enclosure CAD, firmware implementation, USB data, USB Power Delivery, wireless connectivity, batteries, user controls, and compliance testing are outside this project. These exclusions do not waive the electrical and mechanical interface requirements above.

## Acceptance criteria

The design is acceptable only when schematic ERC and PCB DRC pass; all four LED pins are verified as hardware-PWM-capable; AVR ISP operation is compatible with the fitted LED networks; the current and protection budgets are demonstrated from component limits; LED and mechanical coordinates match this specification; all required markings and test points are present; and BOM sourcing plus top-side assembly constraints are satisfied.
