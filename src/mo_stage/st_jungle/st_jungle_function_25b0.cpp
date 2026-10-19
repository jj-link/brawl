#pragma force_active on
extern const float lbl_51_rodata_40;

extern "C" int fn_51_25B0(char* self, int unused, int* out1, int* out2) {
    if (*(unsigned char*)(self + 0x464) == 0) {
        return 0;
    }
    if (*(float*)(self + 0x460) >= lbl_51_rodata_40) {
        *out1 = 6;
        *out2 = 4;
        return 1;
    }
    return 0;
}
