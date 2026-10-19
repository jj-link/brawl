#pragma force_active on
extern "C" const float lbl_67_rodata_B0;
extern "C" const float lbl_67_rodata_DC;

extern "C" void fn_67_9A48(unsigned char* self, int a, int b, unsigned int flag) {
    unsigned int r0 = 0;
    if (lbl_67_rodata_B0 == *(float*)(self + 0x164)) {
        r0 = 1;
    }
    if (flag == 1) {
        r0 = 1;
    }
    *(float*)(self + 0x164) = lbl_67_rodata_DC;
    if (r0 == 1) {
        self[0x160] = 1;
    }
}
