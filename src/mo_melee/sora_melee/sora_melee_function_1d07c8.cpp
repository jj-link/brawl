#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

extern "C" {
void* fn_27_1D07C8(void* p, s32 idx) {
    s32 v = *(s32*)((u8*)p + 8);
    s32 i = (v >> 28) + idx;
    if (i >= 4) {
        i -= 4;
    }
    return (u8*)p + i * 12 + 12;
}
}
