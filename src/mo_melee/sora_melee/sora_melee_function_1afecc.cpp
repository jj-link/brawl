#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void *fn_27_1AFECC(void *self, s32 n)
{
    u8 *p = (u8 *)self;
    s32 idx = (*(s32 *)(p + 8) >> 22) + n;
    if (idx >= 0x119) {
        idx -= 0x119;
    }
    return p + 0xc + idx * 4;
}
}
