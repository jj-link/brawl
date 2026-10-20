#pragma force_active on
extern const unsigned char lbl_27_rodata_2A60[];

extern "C" unsigned int fn_27_1DCBFC(int idx) {
    return (lbl_27_rodata_2A60[idx] >> 4) & 1;
}
