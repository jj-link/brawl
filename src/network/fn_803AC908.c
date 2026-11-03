#include <revolution/types.h>
#pragma force_active on

typedef struct Obj {
    u8 pad0[4];
    u32 unk4;
    u8 pad8[4];
    u16 unkC;
    u8 padE[6];
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u8 unk20;
} Obj;

s32 fn_803AC504(u32, s32 *);
s32 fn_803ADE64(u32, u8 *);
s32 fn_803ADF24(u32, u8 *);

s32 fn_803AC908(Obj *arg0) {
    s32 sp8[6];
    u8 buf[0x60];
    u16 idx;
    s32 r;
    s32 var;
    u32 off;
    u32 val;

    idx = arg0->unkC;
    r = fn_803ADE64(arg0->unk4, buf);
    if (r != 0 && r != 5) {
        return r;
    }
    if (r != 5) {
        if (idx < 4) {
            off = idx * 0x14;
            val = *(u32 *)(buf + 0x14 + off);
            if (val == 0) {
                return 7;
            }
            arg0->unk14 = val;
            arg0->unk18 = *(u32 *)(buf + 0x18 + off);
            arg0->unk20 = *(u8 *)(buf + 9 + off);
            arg0->unk1C = *(u32 *)buf;
            goto block_22;
        }
        for (var = 4; ; var++) {
            r = fn_803ADF24(arg0->unk4, buf);
            if (r != 0 && r != 6) {
                return r;
            }
            if (r != 6) {
                if (idx == (u16)var) {
                    arg0->unk14 = *(u32 *)(buf + 0x14);
                    arg0->unk18 = *(u32 *)(buf + 0x18);
                    arg0->unk20 = buf[9];
                    arg0->unk1C = *(u32 *)buf;
                    goto block_22;
                }
            } else {
                return 7;
            }
        }
    }
    if (idx >= 1) {
        return 7;
    }
    r = fn_803AC504(arg0->unk4, &sp8[0]);
    if (r != 0) {
        return r;
    }
    arg0->unk14 = 0;
    arg0->unk18 = sp8[0];
    arg0->unk20 = 0;
    arg0->unk1C = 0;
block_22:
    return 0;
}
