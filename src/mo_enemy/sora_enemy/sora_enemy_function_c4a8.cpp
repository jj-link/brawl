#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" u64 fn_41_C4A8()
{
    union {
        struct { u32 a, b; } words;
        u64 value;
    } result;

    result.words.a = 0;
    result.words.b = 0;
    return result.value;
}
