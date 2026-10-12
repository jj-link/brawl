struct LuigiZeroVector {
    float x;
    float y;
};

extern "C" const float lbl_99_rodata_60;

extern "C" LuigiZeroVector fn_99_10ACC(void*) {
    LuigiZeroVector result = {lbl_99_rodata_60, lbl_99_rodata_60};
    return result;
}
