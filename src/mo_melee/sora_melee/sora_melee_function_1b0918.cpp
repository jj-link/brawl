#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void* fn_27_1B0918(void* self, s32 idx) {
    s32 v = *(s32*)((u8*)self + 8) >> 27;
    s32 t = v + idx;
    if (t >= 12) {
        t -= 12;
    }
    return (u8*)self + t * 0x68 + 0xC;
}
}
