#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Obj {
    u8 pad0[0x10];
    s32 unk10;
    s32 unk14;
    u16 unk18;
    u16 unk1A;
    u8 pad1C[7];
    u8 unk23;
    u8 unk24;
    u8 pad25[0x51];
    u8 unk76;
    u8 pad77[8];
    u8 unk7F;
    u8 unk80;
    u8 unk81;
    u8 pad82[3];
    u8 unk85;
} Obj;

typedef struct Ent {
    u16 unk0;
    u8 pad2[9];
    u8 unkB;
    u8 padC;
    u8 unkD;
} Ent;

extern void fn_802319E4(s32, void *);
extern void fn_802319FC(s32, void *, s32);
extern void fn_80231A74(s32, void *, s32, s32, s32, s32, s32, s32);
extern Obj *fn_80239F18(u8 *);
extern Obj *fn_8023A0F0(u8 *);
extern u8 *fn_8023B434(void *);
extern u8 fn_8023B8DC(u8 *, s32);
extern Ent *fn_8023C7FC(u8 *, u8);
extern u8 fn_80244A84(u8 *, s32, u8, u8, u16, s32);
extern u8 fn_80245288(u16);
extern void fn_80245F58(s32);
extern u8 fn_802464CC(u8);
extern void *memcpy(void *, const void *, u32);
extern u8 lbl_804814C8[];
extern u8 lbl_80529CF8[];

s32 fn_8023FA20(u8 *arg0, u32 arg1, u8 *arg2, u32 *arg3)
{
    u8 *base = lbl_804814C8;
    Obj *obj;
    Ent *ent;
    u8 r;
    u8 temp_r4;
    s32 temp_r27;

    if (lbl_80529CF8[0x27C0] >= 3) {
        fn_80231A74(0xD0002, base + 0x230, arg0[0], arg0[1], arg0[2], arg0[3], arg0[4], arg0[5]);
    }
    if (arg1 > 0x10) {
        if (lbl_80529CF8[0x27C0] >= 1) {
            fn_802319FC(0xD0000, base + 0x260, arg1);
        }
        return 5;
    }
    obj = fn_8023A0F0(arg0);
    if (obj == 0) {
        obj = fn_80239F18(arg0);
        if (obj == 0) {
            if (lbl_80529CF8[0x27C0] >= 1) {
                fn_802319E4(0xD0000, base + 0x280);
            }
            return 3;
        }
    }
    if (obj->unk18 != 0xFFFF && (obj->unk76 & 2)) {
        if (lbl_80529CF8[0x27C0] >= 2) {
            fn_802319E4(0xD0001, base + 0x2A0);
        }
        return 0;
    }
    if (fn_8023B8DC(arg0, 0) != 0) {
        return 3;
    }
    obj->unk81 = 0x50;
    obj->unk80 = 1;
    obj->unk10 = arg3[0];
    obj->unk14 = arg3[1];
    lbl_80529CF8[0x197F] = arg1;
    if (arg1 != 0) {
        memcpy(lbl_80529CF8 + 0x1980, arg2, arg1);
    }
    obj->unk76 &= ~0x16;
    if ((obj->unk23 & 0x1F) == 5 && (obj->unk24 & 0x40) && lbl_80529CF8[0x20] != 1) {
        lbl_80529CF8[0x197C] = 1;
        fn_80245F58(1);
    }
    lbl_80529CF8[0x197E] = 0;
    if (obj->unk18 != 0xFFFF) {
        obj->unk76 &= ~0x10;
        obj->unk7F = 1;
        if (fn_80245288(obj->unk18) == 0) {
            return 3;
        }
        lbl_80529CF8[0x197D] = 0;
        return 1;
    }
    if (lbl_80529CF8[0x1978] != 3) {
        if (lbl_80529CF8[0x27C0] >= 5) {
            fn_802319E4(0xD0004, base + 0x2C0);
        }
        if (fn_802464CC(1) == 0) {
            if (lbl_80529CF8[0x27C0] >= 1) {
                fn_802319E4(0xD0000, base + 0x2E4);
            }
            return 3;
        }
        lbl_80529CF8[0x197B] = 1;
    }
    lbl_80529CF8[0x197D] = 1;
    temp_r4 = *fn_8023B434(lbl_80529CF8);
    obj->unk85 = 0;
    temp_r27 = (temp_r4 >> 5) & 1;
    ent = fn_8023C7FC(arg0, temp_r4);
    if (ent != 0) {
        r = fn_80244A84(arg0, 0x18, ent->unkB, ent->unkD, ent->unk0 | 0x8000, temp_r27);
    } else {
        r = fn_80244A84(arg0, 0x18, 1, 0, obj->unk1A, temp_r27);
    }
    if (r != 0) {
        return 1;
    }
    if (lbl_80529CF8[0x27C0] >= 1) {
        fn_802319E4(0xD0000, base + 0x2E4);
    }
    if (lbl_80529CF8[0x197B] != 0) {
        lbl_80529CF8[0x197B] = 0;
        if (lbl_80529CF8[0x27C0] >= 5) {
            fn_802319FC(0xD0004, base + 0x2FC, (lbl_80529CF8[0x1978] - 3) == 0);
        }
        fn_802464CC((u8)((lbl_80529CF8[0x1978] - 3) == 0));
    }
    return 3;
}
