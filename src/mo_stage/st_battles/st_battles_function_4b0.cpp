#pragma force_active on
// Constants remain owned by the original module's read-only data unit.
extern "C" const float lbl_42_rodata_0;

extern "C" float fn_42_4B0(void) { return lbl_42_rodata_0; }
