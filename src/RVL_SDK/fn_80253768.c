#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Sub {
    u8 pad[0x6A];
    u16 unk6A;
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
extern void fn_802319E4(u32, const char *);
extern void fn_802319FC(int, const char *, u32);
extern void fn_80231A14(u32, const char *, u8, u32);
extern void fn_80240674(void *);
extern void fn_8025092C(void *, u8, u16);
extern void fn_8025111C(void *, u8);
extern void fn_802516E4(void *, s32);
extern void fn_80254B44(void *, u8);
extern void fn_80254BF4(void *, u8, s32);
extern void fn_80256638(void *);

extern u8 lbl_8052D5A8[];
extern char lbl_80484708[];

void fn_80253768(Obj *arg0, u32 arg1, u8 *arg2) {
    char *base = lbl_80484708;

    switch (arg1) {
    case 15:
        if (*arg2 != 0) {
            if (arg0->unk6C != 0) {
                fn_80254BF4(arg0->unk6C, arg0->unkD, 1);
                fn_802516E4(arg0, 0xF);
            }
        } else {
            fn_8025092C(arg0->unk6C, arg0->unkD, arg0->unk6C->unk6A);
        }
        return;
    case 9:
    case 12:
        if (lbl_8052D5A8[0x414] >= 1U) {
            fn_80231A14(0x90000, base + 0x14, arg0->unk68, arg1);
        }
        return;
    case 13:
        fn_80240674((u8 *)arg0->unk6C + 0x62);
        fn_80256638(arg0);
        return;
    case 14:
        if (lbl_8052D5A8[0x414] >= 1U) {
            fn_802319E4(0x90000, base + 0xFC);
        }
        fn_8022F0E0((s32)arg2);
        return;
    case 0:
        return;
    case 3:
        fn_80240674((u8 *)arg0->unk6C + 0x62);
        arg0->unk68 = 0;
        fn_80254B44(arg0->unk6C, arg0->unkD);
        fn_8025111C(arg0->unk6C, arg0->unkD);
        return;
    case 4:
        fn_8022F0E0((s32)arg2);
        return;
    case 11:
        if (*arg2 != 0) {
            if (arg0->unk6C != 0) {
                fn_80254BF4(arg0->unk6C, arg0->unkD, 1);
            }
        } else {
            fn_80254B44(arg0->unk6C, arg0->unkD);
            arg0->unk68 = 4;
        }
        return;
    default:
        if (lbl_8052D5A8[0x414] >= 2U) {
            fn_802319FC(0x90001, base + 0x128, arg1);
        }
        return;
    }
}
