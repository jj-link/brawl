#include <types.h>
#pragma force_active on

int fn_803928F4(unsigned char *out, s8 in)
{
    s32 hi, lo;
    if (in == 0x20) {
        *out = 0x2B;
        return 1;
    }
    if ((in >= 0x30 && in <= 0x39) || (in >= 0x41 && in <= 0x5A) || (in >= 0x61 && in <= 0x7A)) {
        *out = (unsigned char)in;
        return 1;
    }
    hi = ((u32)in >> 4) & 0xF;
    *out = '%';
    lo = in & 0xF;
    out[1] = (hi < 0x0A) ? (hi + 0x30) : (hi + 0x37);
    out[2] = (lo < 0x0A) ? (lo + 0x30) : (lo + 0x37);
    return 3;
}
