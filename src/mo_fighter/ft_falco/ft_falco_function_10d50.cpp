#pragma force_active on
typedef unsigned long long u64;
typedef unsigned int u32;

extern "C" const float lbl_108_rodata_20;

// The eight-byte input values are returned in the r3/r4 register pair.
union InputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" u64 fn_108_10D50(void) {
    InputPair result;
    result.stick.x = lbl_108_rodata_20;
    result.stick.y = lbl_108_rodata_20;
    return result.packed;
}
