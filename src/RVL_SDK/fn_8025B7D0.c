#include <types.h>
#pragma force_active on

u8 *fn_8025B7D0(u8 *p, u32 max, u16 *out)
{
    u32 len;
    u32 size;
    s32 tag;
    s32 low;
    u8 *end;

    *out = 0;
    tag = *p;
    low = tag & 7;
    if ((u32)(tag >> 3) != 6)
        return p + 1;

    switch (low) {
    case 5:
        len = p[1];
        p += 2;
        break;
    case 6:
        len = (u16)((p[1] << 8) + p[2]);
        p += 3;
        break;
    case 7:
        len = (p[1] << 24) + ((p[2] << 16) + (p[4] + (p[3] << 8)));
        p += 5;
        break;
    default:
        return p + 1;
    }

    if (len > max)
        return p;

    end = p + len;
    while (p < end) {
        tag = *p++;
        low = tag & 7;
        if ((u32)(tag >> 3) != 1)
            return p;

        switch (low) {
        case 1:
            size = 2;
            break;
        case 2:
            size = 4;
            break;
        case 5:
            size = *p++;
            break;
        case 6:
            size = (u16)((p[0] << 8) + p[1]);
            p += 2;
            break;
        case 7:
            size = (p[0] << 24) + (p[1] << 16) + (p[3] + (p[2] << 8));
            p += 4;
            break;
        default:
            return 0;
        }

        if (size == 2) {
            out[1 + *out * 2] = (p[0] << 8) + p[1];
            p += 2;
            out[2 + *out * 2] = out[1 + *out * 2];
        } else if (size == 4) {
            out[1 + *out * 2] = (p[0] << 8) + p[1];
            out[2 + *out * 2] = (p[2] << 8) + p[3];
            p += 4;
        } else {
            return 0;
        }

        *out += 1;
        if (*out >= 16)
            return 0;
    }

    return p;
}
