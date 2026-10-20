#pragma force_active on
extern "C" {
extern const unsigned char lbl_27_rodata_2A60[0xA0];

int fn_27_1DCBD4(int idx) {
    return (lbl_27_rodata_2A60[idx] >> 2) & 1;
}
}
