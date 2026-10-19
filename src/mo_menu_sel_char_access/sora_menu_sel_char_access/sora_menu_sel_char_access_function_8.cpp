#pragma force_active on
extern "C" {

extern const unsigned char lbl_17_section4_0[0x48];

int fn_17_8(int a) {
    if (a < 0 || a >= 0x23) {
        return 0x28;
    }
    return lbl_17_section4_0[a * 2];
}

}
