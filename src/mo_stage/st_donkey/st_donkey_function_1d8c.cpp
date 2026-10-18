#pragma force_active on
// Constants remain owned by the original module's read-only data unit.
extern "C" const float lbl_50_rodata_C;

extern "C" float fn_50_1D8C(void) { return lbl_50_rodata_C; }
