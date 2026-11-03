#pragma force_active on
typedef signed char s8;
typedef signed int s32;

extern int lbl_805A0FA8;

void fn_80342168(void)
{
    s32 bits;
    s8 *base;
    s32 count;
    s32 i;

    base = (s8 *)lbl_805A0FA8;
    bits = *(s32 *)(base + 0x308);
    count = -1;
    for (i = 0; i < 32; i++) {
        if ((1 << i) & bits) {
            count += 1;
        }
    }
    if (count == -1) {
        *(base + 0xE) = 0;
    } else {
        *(base + 0xE) = (s8)count;
    }
}
