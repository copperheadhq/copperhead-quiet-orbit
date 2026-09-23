# Design changelog

## 2026-09-21: create pipeline stage: devplan

- Change: create-devplan-stage
- Files: docs/DEVPLAN.md, docs/CHANGELOG.md, docs/DECISIONS.md
- Verification: ERC clean, DRC clean

## 2026-09-21: create pipeline stage: devplan

- Change: create-devplan-stage
- Files: docs/DEVPLAN.md, docs/CHANGELOG.md, docs/DECISIONS.md
- Verification: ordered bring-up traces TP1 VBUS, TP2 VCC, TP3 GND, and TP4 RESET to measurable stop conditions; prototype ordering is gated on completed routing, verified parts and footprints, restored release DRC checks, regenerated outputs, and staged validation; ERC, DRC, legibility, and documentation drift must remain clean.

## 2026-09-21: create pipeline stage: firmware

- Change: create-firmware-stage
- Files: firmware/pins.h, firmware/led_pwm.h, firmware/led_pwm.c, firmware/main.c, firmware/Makefile, firmware/DEVPLAN.md, docs/CHANGELOG.md, docs/DECISIONS.md
- Verification: ERC clean, DRC clean

## 2026-09-21: create pipeline stage: firmware

- Change: create-firmware-stage
- Files: firmware/pins.h, firmware/led_pwm.h, firmware/led_pwm.c, firmware/main.c, firmware/Makefile, firmware/DEVPLAN.md, docs/CHANGELOG.md, docs/DECISIONS.md
- Verification: pin mapping traced to docs/PINOUT.md; AVR toolchain execution was unavailable, so firmware/DEVPLAN.md explicitly records `not compiled here`; ERC, DRC, legibility, and documentation drift must remain clean.

## 2026-09-21: create pipeline stage: outputs

- Change: create-outputs-stage
- Files: outputs/, outputs/BOM.csv, docs/CHANGELOG.md, docs/DECISIONS.md
- Verification: ERC clean, DRC clean

## 2026-09-21: create pipeline stage: outputs

- Change: create-outputs-stage
- Files: outputs/, docs/CHANGELOG.md, docs/DECISIONS.md
- Verification: JLC Gerbers and drill, DXF and STEP outline, schematic and PCB SVG renders, and ordering BOM.csv must all export successfully; ERC, DRC, legibility, and documentation drift must remain clean.
- Release status: fabrication and ordering artifacts retain the documented draft-layout and UNVERIFIED-MPN limitations and are not release-authorized without specialist review.

## 2026-09-21: create pipeline stage: layout-draft

- Change: create-layout-draft-stage
- Files: quiet-orbit-qo-r1-usb-c-four-light-ambient-lamp-board.kicad_pcb, docs/LAYOUT.md, docs/CHANGELOG.md, docs/DECISIONS.md, quiet-orbit-qo-r1-usb-c-four-light-ambient-lamp-board.kicad_pro
- Verification: ERC clean, DRC clean

## 2026-09-21: create pipeline stage: layout-draft

- Change: create-layout-draft-stage
- Files: quiet-orbit-qo-r1-usb-c-four-light-ambient-lamp-board.kicad_pcb, quiet-orbit-qo-r1-usb-c-four-light-ambient-lamp-board.kicad_pro, docs/LAYOUT.md, docs/CHANGELOG.md, docs/DECISIONS.md
- Verification: exact placement coordinates recorded; routed power-entry nets require clean DRC; documentation drift required clean

Append-only, newest first. One entry per committed copperhead run.

## 2026-09-21: create pipeline stage: schematic

- Change: create-schematic-stage
- Files: schematic.intent.json, quiet-orbit-qo-r1-usb-c-four-light-ambient-lamp-board.kicad_sch, docs/SUBSYSTEMS.md, docs/PINOUT.md, docs/CHANGELOG.md, docs/DECISIONS.md
- Verification: ERC clean

## 2026-09-21: create pipeline stage: schematic

- Change: create-schematic-stage
- Files: schematic.intent.json, quiet-orbit-qo-r1-usb-c-four-light-ambient-lamp-board.kicad_sch, docs/PINOUT.md, docs/SUBSYSTEMS.md, docs/DECISIONS.md, docs/CHANGELOG.md
- Verification: canonical installed symbols and real pins checked; deterministic draft generated; ERC, legibility, and documentation drift required clean

## 2026-09-21: create pipeline stage: part-selection

- Change: create-part-selection-stage
- Files: docs/BOM.md, docs/CHANGELOG.md, docs/DECISIONS.md
- Verification: ERC not required

## 2026-09-21: create pipeline stage: part-selection

- Change: create-part-selection-stage
- Files: docs/BOM.md, docs/DECISIONS.md, docs/CHANGELOG.md
- Verification: installed KiCad symbols and package pins checked for every IC, connector, active/protection part, and test point; electrical budgets calculated; documentation drift check required

## 2026-09-21: create pipeline stage: architecture

- Change: create-architecture-stage
- Files: docs/SUBSYSTEMS.md, docs/CHANGELOG.md, docs/DECISIONS.md
- Verification: ERC not required

## 2026-09-21: create pipeline stage: architecture

- Change: create-architecture-stage
- Files: docs/SUBSYSTEMS.md, docs/DECISIONS.md, docs/CHANGELOG.md
- Verification: documentation drift check; ERC and DRC not required

## 2026-09-21: create pipeline stage: spec-seed

- Change: seed-qo-r1-spec
- Files: docs/SPEC.md, docs/DECISIONS.md
- Verification: ERC not required
