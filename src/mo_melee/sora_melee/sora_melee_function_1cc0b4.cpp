#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void *fn_27_1CC0B4(u8 *self, s32 idx)
{
    s32 v = *(s32 *)(self + 0x18);
    s32 k = (v >> 28) + idx;
    if (k >= 4) {
        k -= 4;
    }
    return self + k * 12 + 0x1c;
}
}
