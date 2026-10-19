#pragma force_active on
typedef unsigned long long u64;

extern "C" const float lbl_77_rodata_48;

union DxPair {
    struct { float x, y; } stick;
    u64 packed;
};

extern "C" u64 fn_77_3368(void) {
    DxPair result;
    result.stick.x = lbl_77_rodata_48;
    result.stick.y = lbl_77_rodata_48;
    return result.packed;
}
