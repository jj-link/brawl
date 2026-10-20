#pragma force_active on
typedef int s32;
typedef unsigned char u8;

extern "C" void* fn_27_F97A8(void* p, s32 idx) {
    s32 v = *(s32*)((u8*)p + 0x18);
    s32 i = (v >> 27) + idx;
    if (i >= 12) {
        i -= 12;
    }
    return (u8*)p + i * 12 + 0x1c;
}
