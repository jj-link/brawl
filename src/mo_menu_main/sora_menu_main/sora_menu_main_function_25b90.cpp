#pragma force_active on
extern "C" {
extern unsigned char lbl_2_rodata_B40[];

unsigned char fn_2_25B90(int idx) {
    unsigned char* p = lbl_2_rodata_B40 + idx * 20;
    return p[8];
}
}
