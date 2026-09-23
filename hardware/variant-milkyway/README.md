# Milky Way variant

The same circuit and the same placement, with the back of the board turned into a picture: the
Milky Way arching over a mountain, built from three finishes a fab can produce:
copper with a mask opening (gold, on ENIG), copper under mask (purple) and bare laminate
(dark purple), plus silkscreen for the stars.

`*.kicad_pcb` and `*.kicad_pro` here replace the two files of the same name one directory up.
Everything else in the project (schematic, rules, libraries) is shared.

Differences from the plain board:

- 4 mm rounded corners.
- No back GND pour. The artwork needs bare laminate for its dark sky. The artwork's gold
  frame, including eyelets around the M3 holes, becomes the GND ring instead, because the
  USB-C receptacle reaches ground partly through its shell stakes and that pour.
- The artwork's copper is floating polygons with no net, cut back from every pad, via, track
  and hole. Large areas of intentionally floating exposed copper will look like an error to a
  fab's reviewer. Say so on the order.
- Requires ENIG, not HASL. HASL would tin the exposed copper and the picture would be lost.

DRC at all severities with schematic parity after the artwork was applied: 0 / 0 / 0.
