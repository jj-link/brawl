#pragma force_active on
extern "C" {
extern const unsigned int lbl_27_rodata_27F8[];

unsigned int fn_27_1DCB6C(int idx) {
    int ok;
    if (idx <= -1 || idx >= 0x9a) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok == 0) {
        return 0;
    }
    return lbl_27_rodata_27F8[idx];
}
}
