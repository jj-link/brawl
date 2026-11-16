#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long size_t;

void* memcpy(void*, const void*, size_t);

#define CP(d, s) { u32 t = *(s)++; *(d)++ = t; }

void fn_8034F028(void* dst, const void* src, u32 n) {
    s32 hw;
    s32 i;
    u16* dh;
    const u16* sh;
    u32* dw;
    const u32* sw;
    u8* db;
    const u8* sb;

    if (n & 0x80000000) {
        memcpy(dst, src, n);
    }
    if (((u32)dst & 3) || ((u32)src & 3)) {
        if (((u32)dst & 1) || ((u32)src & 1)) {
            memcpy(dst, src, n);
            return;
        }
        dh = (u16*)dst;
        sh = (const u16*)src;
        hw = n >> 1;
        if (hw != 0) {
            for (i = hw >> 4; i > 0; i--) {
                *dh++ = *sh++; *dh++ = *sh++; *dh++ = *sh++; *dh++ = *sh++;
                *dh++ = *sh++; *dh++ = *sh++; *dh++ = *sh++; *dh++ = *sh++;
                *dh++ = *sh++; *dh++ = *sh++; *dh++ = *sh++; *dh++ = *sh++;
                *dh++ = *sh++; *dh++ = *sh++; *dh++ = *sh++; *dh++ = *sh++;
            }
            switch (hw & 0xF) {
            case 15: *dh++ = *sh++;
            case 14: *dh++ = *sh++;
            case 13: *dh++ = *sh++;
            case 12: *dh++ = *sh++;
            case 11: *dh++ = *sh++;
            case 10: *dh++ = *sh++;
            case 9: *dh++ = *sh++;
            case 8: *dh++ = *sh++;
            case 7: *dh++ = *sh++;
            case 6: *dh++ = *sh++;
            case 5: *dh++ = *sh++;
            case 4: *dh++ = *sh++;
            case 3: *dh++ = *sh++;
            case 2: *dh++ = *sh++;
            case 1: *dh++ = *sh++;
            case 0: break;
            }
        }
        db = (u8*)dh;
        sb = (const u8*)sh;
        switch (n & 1) {
        case 1: *db = *sb;
        }
        return;
    }

    dw = (u32*)dst;
    sw = (const u32*)src;
    hw = n >> 2;
    if (hw != 0) {
        for (i = hw >> 3; i > 0; i--) {
            CP(dw, sw) CP(dw, sw) CP(dw, sw) CP(dw, sw)
            CP(dw, sw) CP(dw, sw) CP(dw, sw) CP(dw, sw)
        }
        switch (hw & 7) {
        case 7: *dw++ = *sw++;
        case 6: *dw++ = *sw++;
        case 5: *dw++ = *sw++;
        case 4: *dw++ = *sw++;
        case 3: *dw++ = *sw++;
        case 2: *dw++ = *sw++;
        case 1: *dw++ = *sw++;
        case 0: break;
        }
    }
    db = (u8*)dw;
    sb = (const u8*)sw;
    switch (n & 3) {
    case 3: *db++ = *sb++;
    case 2: *db++ = *sb++;
    case 1: *db++ = *sb++;
    }
}
