#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void* fn_27_1E651C(u8* self, s32 idx) {
    s32 sh = *(s32*)(self + 0x18) >> 30;
    s32 n = sh + idx;
    n = (n >= 1) ? n - 1 : n;
    return self + 0x1c + n * 12;
}
}
