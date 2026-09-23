# Hardware

KiCad 10 project for the Quiet Orbit QO-R1. Open `*.kicad_pro`.

This board has never been fabricated. The series diode D1 (1N4148W) is the wrong part for the
power path; a 1 A Schottky in the same SOD-123 footprint is the better fit.

| File | What |
|---|---|
| `*.kicad_sch` | schematic |
| | *(readable exports: `docs/schematic.pdf`, `docs/schematic.svg`)* |
| `*.kicad_pcb` | 57 × 57 mm, 2 layers |
| `*.kicad_dru` | custom design rules, described below |
| `*.kicad_pro` | project settings, including the rule set used for DRC |
| `schematic.intent.json` | the machine-readable intent the schematic was generated from |
| `sym-lib-table`, `sym-lib-cache/` | project symbols, so the project opens standalone |
| `libs/footprints/` | project footprint libraries, from the KiCad standard set |
| `variant-milkyway/` | alternative back with copper artwork |

## Design rules

Our own conservative set, not any named fab's: clearance 0.2 mm, track 0.25 mm signal and 0.5 mm on
the power rails, via 0.65 / 0.3 mm, copper to edge 0.4 mm, hole clearance 0.25 mm, silk text at
least 1.0 mm. No KiCad severity is changed from default and there are no DRC exclusions.

One scoped rule is in the `.kicad_dru`: hole clearance 0.19 mm between J1 and itself. The
USB-C receptacle's stock land pattern puts its GND pads 0.194 mm from its own locating-peg
holes, which is four errors on any board using that footprint at the board-wide 0.25 mm. The
board-wide rule is untouched. A fab with a hard 0.2 mm NPTH-to-copper limit will query it.

Every two-pad part also carries a thin no-track rule area across its pad gap. This was added
after the autorouter put a track between the pads of an 0603. That passed DRC but is poor
practice.

## Geometry

57 × 57 mm. LED optical centres on a board-centred 40 mm square (NW, NE, SE, SW). Four M3
NPTH holes, each centre 4 mm from both adjacent edges. USB-C centred on one edge and flush
with it. All populated parts on the top side.

57 mm is close to the geometric floor for this brief: at 56.5 mm the LED and M3 courtyards are
0.13 mm apart, and at 56.0 mm they overlap. Going smaller means moving the mounting holes
inside the LED square or abandoning the 40 mm pitch.
