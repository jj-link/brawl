#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" u8* fn_27_F3E7C(u8* self, s32 idx) {
    s32 n = (*(s32*)(self + 0x18) >> 30) + idx;
    if (n >= 1) {
        n -= 1;
    }
    return self + n * 12 + 0x1c;
}
