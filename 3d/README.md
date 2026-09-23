# 3D models

Exported with `kicad-cli` from the 57 mm board. Component bodies are generic KiCad library
models, not the exact manufacturer parts. Use them for fit, not for tolerance.

| File | For |
|---|---|
| `quiet-orbit-57mm.step` | full model: tracks, pads, zones, silkscreen and mask |
| `quiet-orbit-57mm-mechanical.step` | board and component bodies only. Give this one to an enclosure designer |
| `quiet-orbit-57mm.glb` | the full model for a web or Blender viewer |
| `quiet-orbit-57mm-board-only.stl` | bare outline with holes, for a fit-check print |

The board is designed against an 80 × 80 × 25 mm enclosure with four light windows over the
LED positions. Note the 0.47 mm gap between the LED and M3 hole courtyards at each corner: a
baffle or light pipe has to share that corner with a screw head.
