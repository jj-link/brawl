#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef void (*Cb)(s32, u8);

typedef struct Obj {
    u8 unk0;
    u8 pad1;
    u8 unk2;
    u8 pad3;
    u16 unk4;
    u8 pad6[6];
    u8 pad0C;
    u8 unkD;
    u8 unkE;
    u8 pad0F;
    u8 pad10[4];
    u16 unk14;
    u8 pad16[0x56];
    void *unk6C;
    u8 pad70[0x18];
    u32 unk88;
    Cb unk8C;
    Cb unk90;
} Obj;

extern u8 lbl_8052D5A8[];
extern char lbl_80483FA8[];

extern Obj *fn_80251AD0(void *, u16);
extern void fn_80231A2C(s32, char *, s32, s32, s32);
extern void fn_802516E4(Obj *, s32);
extern void fn_802563B4(void *);
extern void fn_80254774(void *, u8, s32);
extern void fn_80254850(void *, u8, void *);

void fn_80250A6C(void *arg0, u16 arg1, u32 arg2, u32 arg3)
{
    Obj *obj;
    Cb cb;

    obj = fn_80251AD0(arg0, arg1);
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_80231A2C(0x90003, lbl_80483FA8, arg1, arg2, arg3);
    }
    if (obj != 0) {
        if (arg3 != 0) {
            obj->unkE = 0xC;
            fn_802516E4(obj, 0xC);
            return;
        }
        if (arg2 != 0 && arg2 < obj->unk14) {
            obj->unk14 = arg2;
        }
        fn_802563B4(arg0);
        cb = obj->unk8C;
        if (cb != 0 && (obj->unk88 & 0x200)) {
            cb(0x200, obj->unk0);
        }
        cb = obj->unk90;
        if (cb != 0) {
            cb(0, obj->unk0);
        }
        obj->unk2 = 2;
        if (obj->unk4 == 0x1103 || obj->unk4 == 0x1111) {
            fn_80254774(obj->unk6C, obj->unkD, 0);
        } else {
            fn_80254850(obj->unk6C, obj->unkD, (u8 *)obj + 0x5A);
        }
    }
}
