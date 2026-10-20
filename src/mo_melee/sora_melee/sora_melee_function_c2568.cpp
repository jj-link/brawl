#pragma force_active on
extern const float lbl_27_rodata_EC8;

extern "C" float fn_27_C2568(unsigned char* p) {
    if (p[0x48] == 0 && p[0x4b] == 0) {
        return *(float*)(p + 0x24);
    }
    return lbl_27_rodata_EC8;
}
