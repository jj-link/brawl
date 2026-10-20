#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void* fn_27_1D0150(void* p, s32 n) {
    s32 v = ((s32*)p)[2];
    s32 idx = (v >> 28) + n;
    if (idx >= 5) {
        idx -= 5;
    }
    return (u8*)p + idx * 12 + 12;
}
