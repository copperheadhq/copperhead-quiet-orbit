# Documentation

The design documents, published as they were written alongside the schematic.

| File | What |
|---|---|
| `QO-R1-summary.pdf` | two-page summary: key figures, LED channels, BOM, checks before ordering |
| `QO-R1-reference.pdf` | full design reference: requirements, circuit, pinout, BOM, power budget, firmware, PCB, fab outputs, status |
| `SPEC.md` | the product specification, with normative requirements and every assumption marked |
| `SUBSYSTEMS.md` | power architecture, LED drive, MCU and programming |
| `PINOUT.md` | the ATtiny84A pin map, and the source of `firmware/pins.h` |
| `BOM.md` | bill of materials, with a rationale per line. Every part number is marked UNVERIFIED |
| `LAYOUT.md` | how the 57 mm board is laid out |
| `DECISIONS.md` | design decisions with reasons, in the order they were made |
| `CHANGELOG.md` | one entry per design stage |
| `schematic.pdf`, `schematic.svg` | the schematic sheet, exported from `hardware/*.kicad_sch` with `kicad-cli` 10.0.4, text stroke weight increased for print and projection. Regenerate rather than edit |

Two caveats on reading them:

- `DECISIONS.md` and `CHANGELOG.md` sometimes reference files that are not in this repository:
  an `outputs/` directory, an `openspec/` workspace and a first-draft 70 mm `LAYOUT.md`. The `LAYOUT.md` here
  is a replacement describing the board this repository actually contains.
- `DECISIONS.md` records the choices as made at the time, including some later found wrong.
  The choice of a 1N4148W as the reverse-blocking diode is one of them; fit a Schottky instead.
