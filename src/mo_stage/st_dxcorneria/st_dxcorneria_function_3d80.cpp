#pragma force_active on
// Constant remains owned by the original module's read-only data unit.
extern "C" const float lbl_82_rodata_10;

extern "C" float fn_82_3D80(void) { return lbl_82_rodata_10; }
