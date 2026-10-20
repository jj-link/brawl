#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" u8* fn_27_1D0C18(u8* p, s32 idx) {
    s32 n = (*(s32*)(p + 8) >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return p + n * 12 + 12;
}
