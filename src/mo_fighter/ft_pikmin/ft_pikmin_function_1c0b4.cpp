#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

union PikminInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_113_1C0B4(void*) {
    PikminInputPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
