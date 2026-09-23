# Fabrication outputs (UNVERIFIED)

**Plotted 2026-09-21 from a board that has never been fabricated, from a BOM in which every
part number is unverified, with one known-wrong part fitted (D1 is a
1N4148W signal diode in the power path; use a 1 A Schottky in the same footprint). These files are published so
the design can be inspected. They are not a released fabrication package.**

If you send these to a fab, that decision is yours.

## What is here

| File | Board |
|---|---|
| `QO-R1-57mm-plain-jlcpcb.zip` | square outline, GND pour both sides |
| `QO-R1-57mm-art-jlcpcb.zip` | Milky Way artwork on the back, 4 mm round corners, no back pour |
| `plain/`, `art/` | the same gerbers unzipped, plus drill maps and `.gbrjob` |
| `QO-R1-57mm-bom-jlcpcb.csv` | BOM, transcribed and not verified |
| `QO-R1-57mm-cpl-jlcpcb.csv` | component placement, rotations uncorrected |
| `plain-drc.json`, `art-drc.json` | the DRC reports taken immediately before plotting |
| `make_bom_cpl.py` | how the BOM and CPL were generated |

Each zip holds 11 files: front and back copper, mask, paste and silkscreen, `Edge_Cuts.gm1`,
`PTH.drl` and `NPTH.drl`. Drill maps and `.gbrjob` are left out of the zips deliberately so a
fab's parser cannot mistake a map for a layer. One BOM and CPL pair serves both boards: the
two schematics are byte-identical and the position exports are the same.

## How they were made

`kicad-cli` 10.0.4. Gerbers: Protel extensions, no X2, no netlist attributes, soldermask
subtracted from silk, zones refilled, 4.6 precision. Drill: Excellon, mm, decimal, absolute
origin, PTH and NPTH separate, oval holes in alternate mode. Drills used: PTH 0.30 (vias),
0.60, 1.00 mm; NPTH 0.65 (connector pegs), 3.20 mm (M3).

DRC ran immediately before plotting with `--severity-all --schematic-parity`: 0 violations,
0 unconnected, 0 parity on both boards. The reports are the `*-drc.json` files here.

## What has not been done

- No fab has DFM-checked these. The rules used are our own conservative set, not a
  named manufacturer's. They were compared against one fab's published 2-layer limits from
  memory only.
- Likely to be queried: the connector's GND pads are 0.194 mm from its own 0.65 mm NPTH
  locating pegs. This is the stock land pattern for that part, and it needs a scoped rule in
  the `.kicad_dru` to pass. Many fabs list 0.2 mm as their NPTH-to-copper floor.
- These have not been opened in a gerber viewer. Do that before you pay for anything.
- The BOM is a transcription. The schematic carries no MPN or supplier field; the part
  numbers come from `docs/BOM.md`, where their author marks every one UNVERIFIED, and the
  supplier codes came from a third-party catalogue mirror on 2026-09-22. None was checked
  against a distributor or a datasheet. Three parts had no match and are left blank. D1 is
  listed as the schematic has it; replace it with a Schottky before ordering.
- Rotations are KiCad's, uncorrected. Assembly houses use a different zero for some
  packages. The SOIC, the USB-C receptacle and the five diodes are the ones to check in a
  placement preview.
- The ISP header is through-hole and is in both files; most assembly services fit it by
  hand at extra cost, or you solder it yourself.
- Test points are omitted from the BOM: they are bare copper pads with nothing to buy.

## If you order the art board

Purple soldermask and ENIG. The artwork is exposed copper, and HASL would tin it. The M3
eyelets and frame are exposed GND, and the large areas of floating exposed copper are
intentional; say so in the order remark if an engineer queries it. Neither board carries an
order-number placeholder, so a fab will put its number wherever it likes unless you ask
otherwise. On the art board, that means somewhere in the picture.

Board size reads as 57.1 mm in the file because the outline line has width. The board is
57 × 57 mm, 2 layers, 1.6 mm.
