#include <types.h>
#pragma force_active on

extern void* fn_803D634C(void* dest, int value, u32 size);

#define SWAP16(v) ((u16)((((v) & 0xFF) << 8) | (((v) >> 8) & 0xFF)))
#define SWAP32(v) ((((v) << 24) | (((v) << 8) & 0xFF0000)) | (((v) >> 24) | (((v) >> 8) & 0xFF00)))

s32 fn_803ECB5C(u8* vol, u8* buf, u32* outType, s32 sectors)
{
    u32 nsec;
    u32 spf;
    s32 type;
    u32 tmp;

    if (sectors != 0) {
        nsec = sectors;
    } else {
        nsec = *(u32*)(vol + 0x54) >> 9;
    }

    if (nsec < 0xFF5) {
        type = 0;
        spf = ((((nsec << 2) - nsec) >> 1) + 0x1FF) >> 9;
    } else if (nsec < 0xFFF5) {
        type = 1;
        spf = ((nsec << 1) + 0x1FF) >> 9;
    } else {
        type = 2;
        spf = ((nsec << 2) + 0x1FF) >> 9;
    }

    fn_803D634C(buf, 0, 0x200);

    buf[0] = 0xEB;
    buf[2] = 0x90;
    buf[0x1FE] = 0x55;
    buf[0x1FF] = 0xAA;

    if ((u32)(buf + 0x18) & 1) {
        buf[0x18] = 0x3F;
        buf[0x19] = 0;
    } else {
        *(u16*)(buf + 0x18) = 0x3F00;
    }
    if ((u32)(buf + 0x1A) & 1) {
        buf[0x1A] = 0xFF;
        buf[0x1B] = 0;
    } else {
        *(u16*)(buf + 0x1A) = 0xFF00;
    }
    if ((u32)(buf + 0xB) & 1) {
        buf[0xB] = 0;
        buf[0xC] = 2;
    } else {
        *(u16*)(buf + 0xC) = 2;
    }
    buf[0xD] = 1;
    if ((u32)(buf + 0xE) & 1) {
        buf[0xE] = 1;
        buf[0xF] = 0;
    } else {
        *(u16*)(buf + 0xE) = 0x100;
    }
    tmp = (u32)(buf + 0x11) & 1;
    buf[0x10] = 2;
    if (tmp != 0) {
        buf[0x11] = 0x80;
        buf[0x12] = 0;
    } else {
        *(u16*)(buf + 0x12) = 0x8000;
    }
    buf[0x15] = 0xF0;

    if (nsec < 0x10000) {
        if ((u32)(buf + 0x13) & 1) {
            buf[0x13] = nsec;
            buf[0x14] = nsec >> 8;
        } else {
            *(u16*)(buf + 0x14) = SWAP16(nsec);
        }
        if ((u32)(buf + 0x20) & 3) {
            buf[0x20] = 0;
            buf[0x21] = 0;
            buf[0x22] = 0;
            buf[0x23] = 0;
        } else {
            *(u32*)(buf + 0x20) = 0;
        }
    } else {
        if ((u32)(buf + 0x13) & 1) {
            buf[0x13] = 0;
            buf[0x14] = 0;
        } else {
            *(u16*)(buf + 0x14) = 0;
        }
        if ((u32)(buf + 0x20) & 3) {
            buf[0x20] = nsec;
            buf[0x21] = nsec >> 8;
            buf[0x22] = nsec >> 16;
            buf[0x23] = nsec >> 24;
        } else {
            *(u32*)(buf + 0x20) = SWAP32(nsec);
        }
    }

    if (type == 2) {
        if (tmp != 0) {
            buf[0x11] = 0;
            buf[0x12] = 0;
        } else {
            *(u16*)(buf + 0x12) = 0;
        }
        if ((u32)(buf + 0x24) & 3) {
            buf[0x24] = spf;
            buf[0x25] = spf >> 8;
            buf[0x26] = spf >> 16;
            buf[0x27] = spf >> 24;
        } else {
            *(u32*)(buf + 0x24) = SWAP32(spf);
        }
        if ((u32)(buf + 0x28) & 1) {
            buf[0x28] = 0;
            buf[0x29] = 0;
        } else {
            *(u16*)(buf + 0x28) = 0;
        }
        if ((u32)(buf + 0x2A) & 1) {
            buf[0x2A] = 0;
            buf[0x2B] = 0;
        } else {
            *(u16*)(buf + 0x2A) = 0;
        }
        if ((u32)(buf + 0x2C) & 3) {
            buf[0x2C] = 2;
            buf[0x2D] = 0;
            buf[0x2E] = 0;
            buf[0x2F] = 0;
        } else {
            *(u32*)(buf + 0x2C) = 0x02000000;
        }
        if ((u32)(buf + 0x30) & 1) {
            buf[0x30] = 1;
            buf[0x31] = 0;
        } else {
            *(u16*)(buf + 0x30) = 0x100;
        }
        buf[0x41] = 0;
        buf[0x42] = 0x29;
        if ((u32)(buf + 0x43) & 3) {
            buf[0x43] = 0x34;
            buf[0x44] = 0x12;
            buf[0x45] = 0;
            buf[0x46] = 0;
        } else {
            *(u32*)(buf + 0x4C) = 0x34120000;
        }
    } else {
        if (tmp != 0) {
            buf[0x11] = 0x80;
            buf[0x12] = 0;
        } else {
            *(u16*)(buf + 0x12) = 0x8000;
        }
        if ((u32)(buf + 0x16) & 1) {
            buf[0x16] = spf;
            buf[0x17] = spf >> 8;
        } else {
            *(u16*)(buf + 0x16) = SWAP16(spf);
        }
        buf[0x25] = 0;
        buf[0x26] = 0x29;
        if ((u32)(buf + 0x27) & 3) {
            buf[0x27] = 0x34;
            buf[0x28] = 0x12;
            buf[0x29] = 0;
            buf[0x2A] = 0;
        } else {
            *(u32*)(buf + 0x30) = 0x34120000;
        }
    }

    *outType = type;
    return 0;
}
