#pragma force_active on
// Constant remains owned by the original module's read-only data unit.
extern "C" const float lbl_85_rodata_6C;

extern "C" float fn_85_5374(void) {
    return lbl_85_rodata_6C;
}
