#pragma force_active on
// Constant remains owned by the original module's read-only data unit.
extern "C" const float lbl_89_rodata_8C;

extern "C" float fn_89_1970(void) {
    return lbl_89_rodata_8C;
}
