#pragma force_active on
extern float lbl_27_rodata_5D5C;

extern "C" float fn_27_2AB498(char* base, int idx) {
    int ok = 0;
    if (idx > -1 && idx < 0xB2) {
        ok = 1;
    }
    if (ok != 0) {
        return *(float*)(base + (idx << 2) + 0x11B4);
    }
    return lbl_27_rodata_5D5C;
}
