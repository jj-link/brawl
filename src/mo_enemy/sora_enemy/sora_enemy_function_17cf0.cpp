#pragma force_active on
typedef int s32;

extern "C" {
    extern float lbl_41_rodata_C3C;
    s32 fn_41_15FD4(s32 a, s32 b);
    float fn_41_1F130();

    float fn_41_17CF0(s32 a, s32 b) {
        if (b == -1) {
            return lbl_41_rodata_C3C;
        }
        fn_41_15FD4(a, b);
        return fn_41_1F130();
    }
}
