#pragma force_active on
extern "C" {
void fn_25_CF8(void*, void*);
extern char lbl_25_data_278[];
extern const float lbl_25_rodata_24;
}

extern "C" void fn_25_1104(char* self) {
    float a[5];
    float b[5];

    *(int*)(self + 0x48) = 0;
    self[0x2C] = self[0x2C] & ~2;

    *(char**)&a[4] = lbl_25_data_278;
    a[0] = lbl_25_rodata_24;
    a[1] = lbl_25_rodata_24;
    a[2] = lbl_25_rodata_24;
    a[3] = lbl_25_rodata_24;
    fn_25_CF8(self + 0x4C, a);

    *(int*)(self + 0xB0) = 0;
    *(float*)(self + 0x98) = lbl_25_rodata_24;
    *(float*)(self + 0x9C) = lbl_25_rodata_24;
    *(float*)(self + 0xA0) = lbl_25_rodata_24;
    *(float*)(self + 0xA4) = lbl_25_rodata_24;

    *(char**)&b[4] = lbl_25_data_278;
    b[0] = lbl_25_rodata_24;
    b[1] = lbl_25_rodata_24;
    b[2] = lbl_25_rodata_24;
    b[3] = lbl_25_rodata_24;
}
