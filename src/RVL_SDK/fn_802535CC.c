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
    u8 unk69;
    u8 pad2[2];
    Sub *unk6C;
} Obj;

extern void fn_8022F0E0(s32);
extern void fn_802319FC(int, const char *, u32);
extern void fn_80231A14(u32, const char *, u8, u32);
extern void fn_80250A6C(void *, u8, u16, s32);
extern void fn_80254B44(void *, u8);
extern void fn_80254CB8(void *, u8);
extern void fn_8025640C(void *, s32);
extern void fn_8025648C(void *);
extern void fn_80256638(void *);

extern u8 lbl_8052D5A8[];
extern char lbl_8048471C[];
extern char lbl_8048479C[];

void fn_802535CC(Obj *arg0, u32 arg1, s32 arg2) {
    Sub *temp;

    switch (arg1) {
    case 9:
    case 11:
        if (lbl_8052D5A8[0x414] >= 1U) {
            fn_80231A14(0x90000, lbl_8048471C, arg0->unk68, arg1);
        }
        return;
    case 12:
        fn_8025640C(arg0, 3);
        fn_80254CB8(arg0->unk6C, arg0->unkD);
        arg0->unk69 = 0;
        arg0->unk68 = 5;
        return;
    case 13:
        fn_80256638(arg0);
        return;
    case 14:
        fn_8022F0E0(arg2);
        break;
    case 1:
        fn_8025648C(arg0);
        arg0->unk68 = 4;
        temp = arg0->unk6C;
        fn_80250A6C(temp, arg0->unkD, temp->unk6A, 0);
        return;
    case 2:
        temp = arg0->unk6C;
        fn_80250A6C(temp, arg0->unkD, temp->unk6A, 1);
        fn_80256638(arg0);
        return;
    case 3:
        fn_80254B44(arg0->unk6C, arg0->unkD);
        temp = arg0->unk6C;
        fn_80250A6C(temp, arg0->unkD, temp->unk6A, 1);
        fn_80256638(arg0);
        return;
    case 0:
        fn_80254B44(arg0->unk6C, arg0->unkD);
        return;
    case 4:
        fn_8022F0E0(arg2);
        return;
    case 5:
        temp = arg0->unk6C;
        arg0->unk68 = 0;
        fn_80250A6C(temp, arg0->unkD, temp->unk6A, 1);
        return;
    }

    if (lbl_8052D5A8[0x414] >= 2U) {
        fn_802319FC(0x90001, lbl_8048479C, arg1);
    }
}
