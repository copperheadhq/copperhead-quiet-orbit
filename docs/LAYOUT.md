# Layout

The board in `hardware/` is 57 × 57 mm, two layers, all parts on the top side.

## Geometry

LED optical centres sit on a board-centred 40 mm square at (8.5, 8.5), (48.5, 8.5), (48.5,
48.5) and (8.5, 48.5) mm (NW, NE, SE, SW, labelled on the silkscreen). The four M3 NPTH holes
are 4 mm from both adjacent edges. The USB-C receptacle is centred on one edge, flush with it.

The four LEDs are vertical with the cathode facing the horizontal centre line and the current-
limiting resistor beside the anode, each anode link a single straight 2.58 mm segment. That
orientation was chosen by generating and measuring three variants: it took the LED-drive nets
from 159 mm and 3 vias to 142 mm and none.

Power-entry parts are grouped directly behind the receptacle, the bulk capacitor 2.7 mm from
the nearest VBUS pad. The MCU bypass capacitor is 2.4 mm from the MCU supply pin and the RESET
pull-up 3.4 mm from RESET.

The MCU and ISP header orientations were searched rather than chosen: all eight combinations
were generated and routed, and the one with the fewest signal vias and the least back-layer
copper was kept: 2 vias and 32 mm, against 3 and 53 mm for the obvious orientation.

Result: 89 track segments, 376.5 mm of track, 24 vias of which 21 are ground stitching.

## How small it can go

With the LEDs on a 40 mm square and the M3 holes 4 mm from each edge, the limit is geometric.
The LED courtyard meets the mounting-hole courtyard on the corner diagonal:

| Edge | LED-to-hole courtyard gap | |
|---|---|---|
| 56.0 mm | −0.22 mm | overlaps; 6 courtyard errors |
| 56.5 mm | +0.13 mm | the floor |
| **57.0 mm** | **+0.47 mm** | the board |
| 58.0 mm | +1.17 mm | |

57 mm is 32.5 cm² against 49 cm² for a 70 mm board, 34 % less area. Going below it means
changing an assumption rather than the layout: mounting holes inside the LED square gives
roughly 46 mm, and dropping the 40 mm LED pitch as well roughly 31 mm, at which point the
shrouded ISP header (38 % of all courtyard area) is the thing to change first. Both figures
are estimates and were never laid out.

Note that under 70 mm a single board no longer qualifies for the assembly tier that includes
factory programming at the fab this was costed against, without panelising. Flashing through
the ISP header is the fallback.

## Things a reviewer should question

- The ISP header's ground pin and the SMD ground pads connect solid to the pours, with no
  thermal relief, because the ISP tracks leave no room for spokes. That through-hole pin is harder to
  hand-solder or rework as a result.
- The USB-C receptacle is SMT-only on a board edge, with no mechanical stakes beyond its own
  shell tabs.
- The "USB-C 5V ONLY" silkscreen has tracks under it. Under mask, legible, cosmetic.
- Test points are in the BOM because the schematic puts them there, and marked DNP in
  `BOM.md`. One of the two is wrong.
- Routing is autorouted. The longest nets are the ISP data line at 55 mm and VCC at 117 mm.
  There are no fiducials, and no fab has run DFM on it.
