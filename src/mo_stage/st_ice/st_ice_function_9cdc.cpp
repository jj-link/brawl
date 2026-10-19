#pragma force_active on
// st_ice: getter returning a float constant held in the module rodata.
extern "C" const float lbl_62_rodata_F8;

extern "C" float fn_62_9CDC(void) { return lbl_62_rodata_F8; }
