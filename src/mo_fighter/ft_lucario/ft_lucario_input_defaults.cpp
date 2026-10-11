#include <types.h>

extern "C" const float lbl_118_rodata_C8;

// The module's eight-byte input values are returned in the r3/r4 register pair.
union LucarioInputPair {
    struct { float x, y; } stick;
    struct { u32 first, second; } words;
    u64 packed;
};

extern "C" s32 fn_118_13DB4(void*) { return -1; }
extern "C" void fn_118_13DBC(void*, u32) {}
extern "C" void fn_118_13DC0(void*, s32, s32) {}
extern "C" void fn_118_13DC4(void*) {}
extern "C" void fn_118_13DC8(void*) {}
extern "C" void fn_118_13DCC(void*, u32, u32, s32, u8) {}

extern "C" u64 fn_118_13DD0(void*) {
    LucarioInputPair result;
    result.words.first = 0;
    result.words.second = 0;
    return result.packed;
}
extern "C" u32 fn_118_13DEC(void*) { return 0; }
extern "C" u64 fn_118_13DF4(void*) {
    LucarioInputPair result;
    result.stick.x = lbl_118_rodata_C8;
    result.stick.y = lbl_118_rodata_C8;
    return result.packed;
}
extern "C" u64 fn_118_13E18(void*) {
    LucarioInputPair result;
    result.stick.x = lbl_118_rodata_C8;
    result.stick.y = lbl_118_rodata_C8;
    return result.packed;
}
extern "C" void fn_118_13E3C(void*) {}
