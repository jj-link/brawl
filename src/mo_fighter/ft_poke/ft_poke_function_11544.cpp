#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

union ReturnPair {
    struct { float x, y; } values;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_116_11544(void) {
    ReturnPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
