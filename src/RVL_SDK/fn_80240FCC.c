#include <types.h>
#pragma force_active on

typedef struct Sub {
    u32 type;
    u32 unk4;
} Sub;

typedef struct Obj {
    Sub *unk0;
    void (*unk4)(void *, void *, u8);
    void *unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u16 unk18;
    u8 pad1A[2];
    u8 unk1C[6];
    u8 unk22[0x13];
    u8 unk35[0x40];
    u8 unk75;
    u8 unk76;
    u8 pad77[8];
    u8 unk7F;
    u8 unk80;
    u8 unk81;
    u8 unk82;
    u8 unk83;
    u8 unk84;
    u8 unk85;
} Obj;

typedef void (*Cb4)(void *, void *, void *, s32);
typedef void (*Cb5)(void *, void *, void *, void *, u8);

extern u8 lbl_80529CF8[];
extern char lbl_80481B6C[];
extern char lbl_804817C4[];

extern void *fn_8023A0F0(void *);
extern void *fn_80239F18(void *);
extern void fn_80231A2C(u32, const char *, u32, u32, u32);
extern void fn_802319FC(s32, const char *, s32);
extern void fn_80232020(void *);
extern void fn_80245F58(u8);
extern void fn_802464CC(u8);
extern u8 fn_80241D40(void *);
extern void fn_80244B64(u16, s32, u8);

void fn_80240FCC(void *arg0, u16 arg1, u32 arg2, u32 arg3)
{
    Obj *obj;
    Cb4 cb4;
    Cb5 cb5;
    u8 *p;
    int i;

    obj = (Obj *)fn_8023A0F0(arg0);

    if (lbl_80529CF8[0x27C0] >= 4) {
        fn_80231A2C(0xD0003, lbl_80481B6C, arg1, arg2, arg3);
    }

    if (obj == 0) {
        if (arg2 == 0) {
            obj = (Obj *)fn_80239F18(arg0);
            if (obj == 0) {
                return;
            }
            goto block_8;
        } else {
            return;
        }
    } else {
        s32 v;
        v = *(s32 *)(lbl_80529CF8 + 0x1974);
        obj->unkC = v;
        *(s32 *)(lbl_80529CF8 + 0x1974) = v + 1;
        obj->unk85 = 1;
block_8:
        if (obj->unk81 & 0x40) {
            if (lbl_80529CF8[0x197B] != 0) {
                lbl_80529CF8[0x197B] = 0;
                if (lbl_80529CF8[0x27C0] >= 5) {
                    fn_802319FC(0xD0004, lbl_804817C4, (lbl_80529CF8[0x1978] - 3) == 0);
                }
                fn_802464CC((u8)((lbl_80529CF8[0x1978] - 3) == 0));
            }
            if (lbl_80529CF8[0x197C] != 0) {
                lbl_80529CF8[0x197C] = 0;
                fn_80245F58(lbl_80529CF8[0x20]);
            }
        }

        if (arg2 != 0) {
            if (arg2 == 5 || arg2 == 6 || arg2 == 0xE || arg2 == 0x18 ||
                arg2 == 0x26 || arg2 == 0x29 || arg2 == 0x25 || arg2 == 0x17 ||
                arg2 == 0x22 || (obj->unk81 & 0x40)) {
                obj->unk81 &= ~0x50;
                obj->unk76 &= ~0x10;
                if (*(s32 *)(lbl_80529CF8 + 0x194C) != 0) {
                    fn_80232020(lbl_80529CF8 + 0x193C);
                    arg2 = 0xE;
                    *(s32 *)(lbl_80529CF8 + 0x194C) = 0;
                }
                if (lbl_80529CF8[0x27BF] == 0xE) {
                    arg2 = 0xE;
                }
                cb4 = *(Cb4 *)(lbl_80529CF8 + 0x191C);
                if (cb4 != 0) {
                    cb4(obj->unk1C, obj->unk22, obj->unk35, arg2);
                    return;
                }
            } else {
                if (obj->unk4 != 0) {
                    if (obj->unk80 != 0 && obj->unk0 != 0 && obj->unk0->type == 3) {
                        obj->unk0->unk4 = 0;
                    }
                    if (arg2 == 8 || arg2 == 0x1F || arg2 == 4) {
                        obj->unk4(obj->unk1C, obj->unk8, 8);
                    } else {
                        obj->unk4(obj->unk1C, obj->unk8, 0xA);
                    }
                }
            }
        } else {
            if ((obj->unk81 & 0x40) && obj->unk82 != 0) {
                u8 old;
                obj->unk82 = 0;
                cb5 = *(Cb5 *)(lbl_80529CF8 + 0x1914);
                if (cb5 != 0) {
                    cb5(obj->unk1C, obj->unk22, obj->unk35, obj->unk22 + 3, obj->unk83);
                }
                p = lbl_80529CF8;
                for (i = 0; i < 2; i++) {
                    cb5 = *(Cb5 *)(p + 0x1924);
                    if (cb5 != 0) {
                        cb5(obj->unk1C, obj->unk22, obj->unk35, obj->unk22 + 3, obj->unk83);
                    }
                    p += 4;
                }
                cb4 = *(Cb4 *)(lbl_80529CF8 + 0x191C);
                if (cb4 != 0) {
                    cb4(obj->unk1C, obj->unk22, obj->unk35, 0);
                }
                old = obj->unk81;
                obj->unk81 = old & ~0x50;
                fn_80244B64(arg1, 0x13, old);
                return;
            }
            obj->unk18 = arg1;
            obj->unk76 &= 0xF8;
            if (arg3 != 0) {
                obj->unk76 |= 6;
            }
            if (lbl_80529CF8[0x1978] == 3) {
                obj->unk76 |= 2;
            }
            obj->unk84 = 0;
            if (!(obj->unk76 & 8) || obj->unk80 != 0) {
                u8 r;
                r = fn_80241D40(obj);
                if (r != 1 && obj->unk4 != 0) {
                    if (obj->unk80 != 0 && obj->unk0 != 0 && obj->unk0->type == 3) {
                        obj->unk0->unk4 = 0;
                    }
                    obj->unk4(obj->unk1C, obj->unk8, r);
                    obj->unk4 = 0;
                }
            }
        }
    }
}
