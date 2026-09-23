#!/usr/bin/env python3
"""JLCPCB BOM and CPL for the 57 mm board, from kicad-cli exports.

  kicad-cli sch export bom --fields 'Reference,Value,Footprint' -o raw-bom.csv  <board>.kicad_sch
  kicad-cli pcb export pos --format csv --units mm --side both -o raw-pos.csv   <board>.kicad_pcb
  python3 make_bom_cpl.py raw-bom.csv raw-pos.csv <outdir>

The schematic carries no MPN or LCSC field, so both come from the table below. MPN is
docs/BOM.md in the workspace, word for word. LCSC is what jlcsearch.tscircuit.com returned for
that MPN on 2026-09-22; "" means no match and JLCPCB will ask for a part at upload.
"""
import csv, sys
from collections import OrderedDict

# value, footprint -> (MPN from docs/BOM.md, LCSC, note)
PARTS = {
    ("1uF", "C_0603_1608Metric"): ("CC0603KRX7R9BB105", "", "no LCSC match for this MPN"),
    ("4.7uF", "C_0805_2012Metric"): ("GRM21BR71A475KA73L", "", "no LCSC match for this MPN"),
    ("100nF", "C_0603_1608Metric"): ("CC0603KRX7R9BB104", "C14663", "basic"),
    ("1N4148W", "D_SOD-123"): ("1N4148W-7-F", "C81598", "basic; listed as 1N4148W, not the -7-F MPN. Wrong part for the power path, fit a Schottky"),
    ("Amber LED", "LED_1206_3216Metric"): ("150120AS75000", "C5478408", "extended; stock 100"),
    ("100mA", "Fuse_0603_1608Metric"): ("MF-FSMF010X-2", "C210355", "extended"),
    ("USB-C", "USB_C_Receptacle_GCT_USB4105-xx-A_16P_TopMnt_Horizontal"): ("USB4105-GF-A", "C3020560", "extended"),
    ("AVR-ISP-6", "IDC-Header_2x03_P2.54mm_Vertical"): ("61200621621", "", "through-hole; no LCSC match for this MPN"),
    ("5.1k", "R_0603_1608Metric"): ("RC0603FR-075K1L", "C105580", "extended"),
    ("10k", "R_0603_1608Metric"): ("RC0603FR-0710KL", "C98220", "extended; stock 22"),
    ("680", "R_0603_1608Metric"): ("RC0603FR-07680RL", "C112310", "extended; stock 71"),
    ("ATtiny84A", "SOIC-14_3.9x8.7mm_P1.27mm"): ("ATTINY84A-SSUR", "C220597", "extended; stock 5 (the tube part, -SSU, is C144333, stock 40)"),
}
SKIP = ("TP",)  # bare copper pads: nothing to buy or place

raw_bom, raw_pos, out = sys.argv[1:4]

groups = OrderedDict()
for r in csv.DictReader(open(raw_bom)):
    ref = r["Reference"]
    if ref.startswith(SKIP):
        continue
    key = (r["Value"], r["Footprint"].split(":")[-1])
    groups.setdefault(key, []).append(ref)

with open(f"{out}/QO-R1-57mm-bom-jlcpcb.csv", "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["Comment", "Designator", "Footprint", "LCSC Part #", "MPN", "Note"])
    for (value, fp), refs in groups.items():
        mpn, lcsc, note = PARTS[(value, fp)]  # KeyError = the schematic changed; update PARTS
        w.writerow([value, ",".join(refs), fp, lcsc, mpn, note])

placed = {ref for refs in groups.values() for ref in refs}
with open(f"{out}/QO-R1-57mm-cpl-jlcpcb.csv", "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["Designator", "Mid X", "Mid Y", "Layer", "Rotation"])
    for r in csv.DictReader(open(raw_pos)):
        if r["Ref"] not in placed:
            continue
        placed.discard(r["Ref"])
        w.writerow([r["Ref"], f'{float(r["PosX"]):.4f}mm', f'{float(r["PosY"]):.4f}mm',
                    r["Side"].capitalize(), f'{float(r["Rot"]) % 360:g}'])
if placed:
    sys.exit(f"in the BOM but not in the position file: {sorted(placed)}")
