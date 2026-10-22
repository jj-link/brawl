#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct Sub {
    u32 type;
    u32 unk4;
} Sub;

typedef struct Obj {
    Sub *unk0;
    void (*unk4)(void *, void *, s32);
    void *unk8;
    u8 pad_c[4];
    s32 unk10;
    s32 unk14;
    u8 pad18[0x5E];
    u8 unk76;
    u8 pad77[8];
    u8 unk7F;
    u8 unk80;
} Obj;

extern void *fn_8023A0F0(void *);
extern void fn_80231A14(int, void *, int, int);
extern void fn_80231A74(int, void *, int, int, int, int, int, int);
extern u8 fn_80241D40(void *);
extern u8 lbl_80529CF8[];
extern char lbl_80481668[];
extern char lbl_804816C8[];

void fn_8023F844(u8 *arg0, s32 arg1, u32 *arg2)
{
    Obj *obj = (Obj *)fn_8023A0F0(arg0);

    if (obj == 0) {
        if (lbl_80529CF8[0x27C0] >= 2) {
            fn_80231A74(0xD0001, lbl_80481668, arg0[0], arg0[1], arg0[2], arg0[3], arg0[4], arg0[5]);
        }
    } else {
        if (lbl_80529CF8[0x27C0] >= 4) {
            fn_80231A14(0xD0003, lbl_804816C8, arg1, obj ? obj->unk7F : 0);
        }
        if (arg1 == 0) {
            obj->unk76 |= 1;
            obj->unk10 = arg2[0];
            obj->unk14 = arg2[1];
        }
        if (obj->unk7F == 4) {
            obj->unk7F = 0;
            if (arg1 != 0) {
                if (obj->unk4 != 0) {
                    if (obj->unk80 != 0 && obj->unk0 != 0 && obj->unk0->type == 3) {
                        obj->unk0->unk4 = 0;
                    }
                    obj->unk4(arg0, obj->unk8, arg1);
                    obj->unk4 = 0;
                }
            } else {
                u8 r = fn_80241D40(obj);
                if (r != 1 && obj->unk4 != 0) {
                    if (obj->unk80 != 0 && obj->unk0 != 0 && obj->unk0->type == 3) {
                        obj->unk0->unk4 = 0;
                    }
                    obj->unk4(arg0, obj->unk8, r);
                    obj->unk4 = 0;
                }
            }
        }
    }
}
