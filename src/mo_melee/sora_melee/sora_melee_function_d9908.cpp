#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void* fn_27_D9908(u8* self, s32 idx) {
    s32 i = (*(s32*)(self + 8) >> 28) + idx;
    if (i >= 5) {
        i -= 5;
    }
    return self + i * 0x34 + 0xc;
}
}
