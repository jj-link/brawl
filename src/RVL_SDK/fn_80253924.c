#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Obj {
    u8 pad0[0xD];
    u8 unkD;
    u8 pad1[0x5A];
    u8 unk68;
    u8 pad2[3];
    char *unk6C;
} Obj;

extern void fn_8022F0E0(s32);
extern void fn_802319E4(u32, const char *);
extern void fn_802319FC(int, const char *, u32);
extern void fn_80231A14(u32, const char *, u8, u32);
extern void fn_80240674(void *);
extern void fn_80250A6C(void *, u8, u16, s32);
extern void fn_80254A94(void *, u8);
extern void fn_8025640C(void *, s32);
extern void fn_80256638(void *);

extern u8 lbl_8052D5A8[];
extern char lbl_80484708[];

void fn_80253924(Obj *arg0, u32 arg1, u8 *arg2) {
    char *base = lbl_80484708;
    char *temp;

    switch (arg1) {
    case 15:
        if (*arg2 != 0) {
            fn_80250A6C(arg0->unk6C, arg0->unkD, 0, 0x70);
            fn_80256638(arg0);
        } else {
            fn_80254A94(arg0->unk6C, arg0->unkD);
            fn_8025640C(arg0, 0x3C);
            arg0->unk68 = 1;
        }
        return;
    case 0:
    case 9:
        if (lbl_8052D5A8[0x414] >= 1U) {
            fn_80231A14(0x90000, base + 0x14, arg0->unk68, arg1);
        }
        return;
    case 12:
        temp = arg0->unk6C;
        fn_80240674(temp + 0x62);
        fn_80256638(arg0);
        return;
    case 14:
        if (lbl_8052D5A8[0x414] >= 1U) {
            fn_802319E4(0x90000, base + 0x198);
        }
        fn_8022F0E0((s32)arg2);
        return;
    case 4:
        fn_8022F0E0((s32)arg2);
        return;
    }

    if (lbl_8052D5A8[0x414] >= 2U) {
        fn_802319FC(0x90001, base + 0x1C8, arg1);
    }
}
