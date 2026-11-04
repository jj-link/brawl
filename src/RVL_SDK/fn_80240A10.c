#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Sub {
    u32 type;
    u32 unk4;
} Sub;

typedef void (*Callback)(u8 *, u8 *, u8 *, s32);

typedef struct Obj {
    Sub *unk0;
    void (*unk4)(void *, void *, u8);
    void *unk8;
    u8 padC[4];
    u32 unk10;
    u32 unk14;
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
} Obj;

extern u8 lbl_80529CF8[];
extern char lbl_80481AD4[];
extern char lbl_804817C4[];
extern void *fn_8023A038(unsigned int);
extern void fn_80231A14(int, void *, int, int);
extern void fn_802319FC(int, void *, int);
extern void fn_802464CC(u8);
extern void fn_80245F58(int);
extern u8 fn_80241D40(Obj *);
extern u8 fn_80244B64(u16, u8);

void fn_80240A10(u16 arg0, u32 arg1)
{
    Obj *obj;
    u8 flags;
    u8 saved;
    u8 old;

    obj = (Obj *)fn_8023A038(arg0);

    if (lbl_80529CF8[0x27C0] >= 4) {
        fn_80231A14(0xD0003, lbl_80481AD4, arg1, obj ? obj->unk7F : 0);
    }

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

    if (obj != 0) {
        flags = obj->unk81;
        if ((flags & 0x40) && lbl_80529CF8[0x197D] == 0) {
            obj->unk81 = flags & ~0x50;
            saved = lbl_80529CF8[0x197E];
            if (saved != 0) {
                Obj *obj2 = (Obj *)fn_8023A038(arg0);
                if (obj2 != 0) {
                    if (obj2->unk81 & 0x40) {
                        lbl_80529CF8[0x197E] = saved;
                    } else {
                        old = obj2->unk7F;
                        if (old != 5) {
                            obj2->unk7F = 5;
                            if (fn_80244B64(arg0, saved) == 0)
                                obj2->unk7F = old;
                        }
                    }
                }
            }
        }
    }

    if (obj != 0) {
        if (obj->unk7F != 1) {
            Callback f = *(Callback *)(lbl_80529CF8 + 0x191C);
            if (f != 0 && arg1 != 0)
                f(obj->unk1C, obj->unk22, obj->unk35, arg1);
        } else {
            if (arg1 == 0xC && (obj->unk76 & 6) == 6)
                arg1 = 0;
            {
                Callback f = *(Callback *)(lbl_80529CF8 + 0x191C);
                if (f != 0)
                    f(obj->unk1C, obj->unk22, obj->unk35, arg1);
            }
            obj->unk7F = 0;
            if (obj->unk81 & 0x40) {
                obj->unk81 &= ~0x50;
                fn_80244B64(obj->unk18, 0x13);
            } else if (arg1 != 0) {
                if (obj->unk4 != 0) {
                    if (obj->unk80 != 0 && obj->unk0 != 0 && obj->unk0->type == 3)
                        obj->unk0->unk4 = 0;
                    obj->unk4(obj->unk1C, obj->unk8, 0xA);
                    obj->unk4 = 0;
                }
                fn_80244B64(obj->unk18, 5);
            } else {
                obj->unk76 |= 2;
                {
                    u8 result = fn_80241D40(obj);
                    if (result != 1 && obj->unk4 != 0) {
                        if (obj->unk80 != 0 && obj->unk0 != 0 && obj->unk0->type == 3)
                            obj->unk0->unk4 = 0;
                        obj->unk4(obj->unk1C, obj->unk8, result);
                        obj->unk4 = 0;
                    }
                }
            }
        }
    }
}
