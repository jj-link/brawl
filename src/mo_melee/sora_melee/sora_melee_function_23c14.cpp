#pragma force_active on
extern const float lbl_27_rodata_390;

extern "C" void fn_27_23C14(char* p) {
    *(float*)(p + 0x60) = lbl_27_rodata_390 * *(float*)(p + 0x40);
}
