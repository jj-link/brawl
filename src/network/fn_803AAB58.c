#include <types.h>
#pragma force_active on

extern void fn_803AAA88(void *);

s32 fn_803AAB58(void *arg0, void *arg1)
{
    s32 result;
    u8 *src;
    u8 *dst;
    s32 type;
    u32 val_68;
    u32 val_6C;
    u8 val_B;
    u32 val_C;

    if (arg0 == 0 || arg1 == 0)
        return 1;

    src = (u8 *)arg0;
    dst = (u8 *)arg1;
    result = 0;

    if (arg0 != 0 && (u8 *)arg1 + 0x4C != 0) {
        dst[0x4C] = src[0];
        dst[0x4D] = src[1];
        dst[0x4E] = src[2];
    }

    if ((u8 *)arg0 + 3 != 0 && arg1 != 0) {
        dst[0] = src[3];
        dst[1] = src[4];
        dst[2] = src[5];
        dst[3] = src[6];
        dst[4] = src[7];
        dst[5] = src[8];
        dst[6] = src[9];
        dst[7] = src[0xA];
    }

    *(u16 *)(dst + 8) = (u16)(src[0xB] | (src[0xC] << 8));
    dst[0xA] = src[0xD];
    *(u16 *)(dst + 0xC) = (u16)(src[0xE] | (src[0xF] << 8));
    dst[0xB] = src[0x10];
    *(u16 *)(dst + 0xE) = (u16)(src[0x11] | (src[0x12] << 8));
    *(u16 *)(dst + 0x10) = (u16)(src[0x13] | (src[0x14] << 8));
    dst[0x22] = src[0x15];
    *(u16 *)(dst + 0x12) = (u16)(src[0x16] | (src[0x17] << 8));
    *(u16 *)(dst + 0x14) = (u16)(src[0x18] | (src[0x19] << 8));
    *(u16 *)(dst + 0x20) = (u16)(src[0x1A] | (src[0x1B] << 8));
    *(u32 *)(dst + 0x18) = (u32)(src[0x1C] | (src[0x1D] << 8) |
                                   (src[0x1E] << 16) | (src[0x1F] << 24));
    *(u32 *)(dst + 0x1C) = (u32)(src[0x20] | (src[0x21] << 8) |
                                   (src[0x22] << 16) | (src[0x23] << 24));

    val_68 = *(u16 *)(dst + 0x10) == 0
        ? *(u32 *)(dst + 0x1C) : *(u16 *)(dst + 0x10);
    *(u32 *)(dst + 0x68) = val_68;

    if (*(u16 *)(dst + 0x12) == 0) {
        *(u32 *)(dst + 0x6C) = *(u32 *)(dst + 0x3C) =
            (u32)(src[0x24] | (src[0x25] << 8) |
                  (src[0x26] << 16) | (src[0x27] << 24));
    } else {
        *(u32 *)(dst + 0x6C) = *(u16 *)(dst + 0x12);
        *(u32 *)(dst + 0x3C) = 0;
    }

    fn_803AAA88(dst);
    type = *(s32 *)(dst + 0x50);

    switch (type) {
    case 0:
    case 1:
        if (*(u16 *)(dst + 0x12) == 0)
            result = 4;

        *(u16 *)(dst + 0x40) = 0;
        *(u16 *)(dst + 0x42) = 0;
        *(u32 *)(dst + 0x44) = 0;
        *(u16 *)(dst + 0x48) = 0;
        *(u16 *)(dst + 0x4A) = 0;
        dst[0x23] = src[0x24];
        dst[0x28] = src[0x26];
        *(u32 *)(dst + 0x24) = (u32)(src[0x27] | (src[0x28] << 8) |
                                       (src[0x29] << 16) | (src[0x2A] << 24));

        if (src + 0x2B != 0 && dst + 0x29 != 0) {
            dst[0x29] = src[0x2B];
            dst[0x2A] = src[0x2C];
            dst[0x2B] = src[0x2D];
            dst[0x2C] = src[0x2E];
            dst[0x2D] = src[0x2F];
            dst[0x2E] = src[0x30];
            dst[0x2F] = src[0x31];
            dst[0x30] = src[0x32];
            dst[0x31] = src[0x33];
            dst[0x32] = src[0x34];
            dst[0x33] = src[0x35];
        }

        if (src + 0x36 != 0 && dst + 0x34 != 0) {
            dst[0x34] = src[0x36];
            dst[0x35] = src[0x37];
            dst[0x36] = src[0x38];
            dst[0x37] = src[0x39];
            dst[0x38] = src[0x3A];
            dst[0x39] = src[0x3B];
            dst[0x3A] = src[0x3C];
            dst[0x3B] = src[0x3D];
        }
        break;

    case 2:
        if (*(u16 *)(dst + 0x10) != 0 || *(u16 *)(dst + 0x12) != 0)
            result = 4;

        *(u16 *)(dst + 0x40) = (u16)(src[0x28] | (src[0x29] << 8));
        *(u16 *)(dst + 0x42) = (u16)(src[0x2A] | (src[0x2B] << 8));
        *(u32 *)(dst + 0x44) = (u32)(src[0x2C] | (src[0x2D] << 8) |
                                       (src[0x2E] << 16) | (src[0x2F] << 24));
        *(u16 *)(dst + 0x48) = (u16)(src[0x30] | (src[0x31] << 8));
        *(u16 *)(dst + 0x4A) = (u16)(src[0x32] | (src[0x33] << 8));
        dst[0x23] = src[0x40];
        dst[0x28] = src[0x42];
        *(u32 *)(dst + 0x24) = (u32)(src[0x43] | (src[0x44] << 8) |
                                       (src[0x45] << 16) | (src[0x46] << 24));

        if (src + 0x47 != 0 && dst + 0x29 != 0) {
            dst[0x29] = src[0x47];
            dst[0x2A] = src[0x48];
            dst[0x2B] = src[0x49];
            dst[0x2C] = src[0x4A];
            dst[0x2D] = src[0x4B];
            dst[0x2E] = src[0x4C];
            dst[0x2F] = src[0x4D];
            dst[0x30] = src[0x4E];
            dst[0x31] = src[0x4F];
            dst[0x32] = src[0x50];
            dst[0x33] = src[0x51];
        }

        if (src + 0x52 != 0 && dst + 0x34 != 0) {
            dst[0x34] = src[0x52];
            dst[0x35] = src[0x53];
            dst[0x36] = src[0x54];
            dst[0x37] = src[0x55];
            dst[0x38] = src[0x56];
            dst[0x39] = src[0x57];
            dst[0x3A] = src[0x58];
            dst[0x3B] = src[0x59];
        }

        if (*(u16 *)(dst + 0x42) != 0)
            result = 4;
        break;

    default:
        result = 4;
        break;
    }

    type = *(s32 *)(dst + 0x50);
    switch (type) {
    case 0:
    case 1:
        val_B = dst[0xB];
        val_6C = *(u32 *)(dst + 0x6C);
        val_C = *(u16 *)(dst + 0xC);
        dst[0x4F] = val_B;
        *(u32 *)(dst + 0x58) = val_C;
        *(u32 *)(dst + 0x5C) = val_C + val_B * val_6C;
        break;

    case 2:
        *(u32 *)(dst + 0x5C) =
            *(u32 *)(dst + 0x60) +
            ((*(u32 *)(dst + 0x44) - 2) << dst[0x55]);

        if (*(u16 *)(dst + 0x40) & 0x80) {
            dst[0x4F] = 1;
            *(u32 *)(dst + 0x58) = *(u16 *)(dst + 0xC) +
                (*(u16 *)(dst + 0x40) & 7) * *(u32 *)(dst + 0x6C);
        } else {
            dst[0x4F] = dst[0xB];
            *(u32 *)(dst + 0x58) = *(u16 *)(dst + 0xC);
        }
        break;
    }

    return result;
}
