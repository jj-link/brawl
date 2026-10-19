#pragma force_active on
extern "C" const float lbl_107_rodata_D8;

union GamewatchInputPair {
    struct { float x, y; } stick;
    struct { unsigned int first, second; } words;
    unsigned long long packed;
};

extern "C" unsigned long long fn_107_16928(void*) {
    GamewatchInputPair result;
    result.stick.x = lbl_107_rodata_D8;
    result.stick.y = lbl_107_rodata_D8;
    return result.packed;
}
