#pragma force_active on
#include <types.h>

typedef struct FatBootInfo {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8 unk06;
    u8 unk07;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u8 unk1A;
    u8 pad1B;
    s32 unk1C;
    u8 pad20;
    u8 unk21;
    u8 unk22;
    u8 pad23[5];
    u32 unk28;
    u32 unk2C;
    u32 unk30;
} FatBootInfo;

extern void fn_803D7330(FatBootInfo *info);
extern s32 fn_803D8228(u8 *buf);

#define SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))
#define SWAP32(x) ((((x) << 24) | (((x) << 8) & 0xFF0000)) | (((x) >> 24) | (((x) >> 8) & 0xFF00)))
#define LD16(p, t, e) ((((u32)(p) + (t)) & 1) ? (u16)((p)[t] | ((p)[(t) + 1] << 8)) : SWAP16(*(u16 *)((p) + (e))))
#define LD32(p, o) SWAP32(*(u32 *)((p) + (o)))

s32 fn_803D7418(FatBootInfo *arg0, u8 *arg1, s32 ret, u16 w13) {
    u16 w16;
    u16 w2a;
    u16 w32;
    u16 f;
    u32 v;
    s32 t;

    ret = 0;
    if (fn_803D8228(arg1) == 0) {
        ret = 3;
    } else {
        arg0->unk00 = LD16(arg1, 0xB, 0xC);
        arg0->unk06 = arg1[0xD];
        arg0->unk02 = LD16(arg1, 0xE, 0xE);
        arg0->unk07 = arg1[0x10];
        arg0->unk04 = LD16(arg1, 0x11, 0x12);
        arg0->unk1A = arg1[0x15];
        w13 = LD16(arg1, 0x13, 0x14);
        if (w13 == 0) {
            v = LD32(arg1, 0x20);
        } else {
            v = w13;
        }
        arg0->unk08 = v;
        w16 = LD16(arg1, 0x16, 0x16);
        if (w16 == 0) {
            v = LD32(arg1, 0x24);
        } else {
            v = w16;
        }
        arg0->unk0C = v;
        fn_803D7330(arg0);
        t = arg0->unk1C;
        switch (t) {
        case 0:
        case 1:
            if (w16 == 0) {
                ret = 4;
            }
            break;
        case 2:
            if (w13 != 0 || w16 != 0) {
                ret = 4;
            }
            w2a = LD16(arg1, 0x2A, 0x2A);
            arg0->unk18 = LD16(arg1, 0x28, 0x28);
            arg0->unk10 = LD32(arg1, 0x2C);
            arg0->unk14 = LD16(arg1, 0x30, 0x30);
            w32 = LD16(arg1, 0x32, 0x32);
            arg0->unk16 = w32;
            arg0->unk2C = arg0->unk30 + ((arg0->unk10 - 2) << arg0->unk21);
            if (w2a != 0) {
                ret = 4;
            }
            break;
        default:
            ret = 4;
            break;
        }
        f = arg0->unk18;
        if (f & 0x80) {
            arg0->unk22 = 1;
            arg0->unk28 = arg0->unk02 + ((f & 7) * arg0->unk0C);
        } else {
            arg0->unk22 = arg0->unk07;
            arg0->unk28 = arg0->unk02;
        }
    }
    return ret;
}
