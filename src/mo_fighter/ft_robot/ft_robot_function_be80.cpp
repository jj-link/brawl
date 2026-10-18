#pragma force_active on
extern "C" {
extern const float lbl_120_rodata_8;
void fn_120_8718(void* position, float x, float y, float z);

void fn_120_BE80(void* position) {
    fn_120_8718(position, lbl_120_rodata_8, lbl_120_rodata_8, lbl_120_rodata_8);
}
}
