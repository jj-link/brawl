#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

union ReturnValue {
    struct {
        u32 first;
        u32 second;
    } words;
    u64 packed;
};

extern "C" u64 fn_110_12CD8(void *) {
    ReturnValue result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
