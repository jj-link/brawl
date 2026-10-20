#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

extern "C" void* fn_27_1B0714(void* p, s32 idx) {
    s32 i = (*(s32*)((u8*)p + 8) >> 28) + idx;
    if (i >= 4) {
        i -= 4;
    }
    return (u8*)p + i * 0x78 + 0xc;
}
