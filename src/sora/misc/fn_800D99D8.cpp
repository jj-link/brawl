#pragma force_active on
extern "C" {
    void netReport__FPCce(const char*, ...);
    int fn_800C8524();
    int fn_8014FDB0();
    unsigned int fn_8014FDC4();
    char lbl_80457158[];
}

extern "C" bool fn_800D99D8() {
    const char* base = lbl_80457158;
    if (fn_800C8524() == 0)
        return false;
    if (fn_8014FDB0() == 0) {
        netReport__FPCce(base + 0x28E4);
        return false;
    }
    if (fn_8014FDC4() == 0) {
        netReport__FPCce(base + 0x290C);
        return false;
    }
    netReport__FPCce(base + 0x294C);
    return true;
}
