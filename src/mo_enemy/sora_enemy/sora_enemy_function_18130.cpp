#pragma force_active on
extern float lbl_41_rodata_C3C;

extern "C" int fn_41_15FD4(int a, int b);
extern "C" float fn_41_1F2D0();

extern "C" float fn_41_18130(int, int b) {
    if (b == -1) {
        return lbl_41_rodata_C3C;
    }
    int a;
    fn_41_15FD4(a, b);
    return fn_41_1F2D0();
}
