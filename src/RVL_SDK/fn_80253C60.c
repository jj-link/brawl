#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct Sub {
    u8 pad[0x74];
    u8 unk74;
} Sub;

typedef struct Obj {
    u8 pad0[0xD];
    u8 unkD;
    u8 pad1[0x5A];
    u8 unk68;
    u8 pad2[3];
    Sub *unk6C;
} Obj;

extern void fn_8022F0E0(s32);
extern void fn_802319FC(int, const char *, u32);
extern void fn_80231A14(u32, const char *, u8, u32);
extern void fn_80254BF4(void *, u8, int);
extern void fn_80256638(void *);
extern u8 lbl_8052D5A8[];
extern char lbl_8048471C[];
extern char lbl_804849A0[];

void fn_80253C60(Obj *arg0, u32 arg1, s32 arg2)
{
    switch (arg1) {
    case 9:
    case 11:
        if (lbl_8052D5A8[0x414] >= 1U) {
            fn_80231A14(0x90000, lbl_8048471C, arg0->unk68, arg1);
        }
        return;
    case 13:
        fn_80256638(arg0);
        return;
    case 14:
        fn_8022F0E0(arg2);
        return;
    case 1:
        arg0->unk6C->unk74 = 1;
        /* fallthrough */
    case 2:
        fn_80256638(arg0);
        return;
    case 0:
        fn_80254BF4(arg0->unk6C, arg0->unkD, 1);
        return;
    case 3:
        fn_80254BF4(arg0->unk6C, arg0->unkD, 1);
        return;
    case 4:
        fn_8022F0E0(arg2);
        fn_80254BF4(arg0->unk6C, arg0->unkD, 0);
        return;
    case 5:
        fn_80256638(arg0);
        return;
    }
    if (lbl_8052D5A8[0x414] >= 2U) {
        fn_802319FC(0x90001, lbl_804849A0, arg1);
    }
}
