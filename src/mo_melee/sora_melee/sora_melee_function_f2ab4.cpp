#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void* fn_27_F2AB4(void* self, s32 idx) {
    s32 t = *(s32*)((u8*)self + 0x18) >> 28;
    s32 i = t + idx;
    if (i >= 5) {
        i -= 5;
    }
    return (u8*)self + i * 12 + 0x1c;
}
