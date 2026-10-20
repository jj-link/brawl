#pragma force_active on
extern "C" int fn_41_1AE30(int);
extern float lbl_41_rodata_C9C;

extern "C" float fn_41_1AFD8(int a, float x, int b) {
    if (fn_41_1AE30(a) != 0) {
        return lbl_41_rodata_C9C;
    }
    if (b < 0) {
        return lbl_41_rodata_C9C;
    }
    return x;
}
