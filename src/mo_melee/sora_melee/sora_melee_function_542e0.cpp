#pragma force_active on
// Per-frame scratch: the two words before +0x8 hold the state that the
// third word tags, and the tag keeps its kind in bit 0 and its sub-field
// selector in the seven bits below it.  Shifting the signed tag word down
// by 23 exposes both of them (bit 23 is the sign bit of the low halfword,
// so the arithmetic shift keeps the sign).
extern "C" int fn_27_542E0(int* scratch) {
    int tag = scratch[2];
    return tag >> 23;
}
