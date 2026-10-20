#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

extern "C" {
void* fn_27_1C8534(u8* self, s32 idx) {
    s32 t = *(s32*)(self + 0x18);
    s32 i = (t >> 26) + idx;
    if (i >= 0x11) {
        i -= 0x11;
    }
    return self + 0x1c + i * 12;
}
}
