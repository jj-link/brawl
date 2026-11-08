#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Baz {
    u8 pad[0x72];
    u8 unk72;
} Baz;

typedef struct Foo {
    u8 pad0[0x0D];
    u8 unkD;
    u8 pad1[6];
    u16 unk14;
    u8 pad2[0x27];
    u8 unk3D;
    u8 pad3[0x2A];
    u8 unk68;
    u8 unk69;
    u8 pad4[2];
    Baz *unk6C;
    u8 pad5[0x2A];
    u16 unk9A;
    u16 unk9C;
} Foo;

typedef struct Bar {
    u8 pad0[2];
    u16 unk2;
    u8 pad1[2];
    u16 unk6;
} Bar;

extern void fn_80231A14(u32, const char *, u8, u32);
extern void fn_802319FC(u32, const char *, u32);
extern void fn_8025640C(void *, int);
extern void fn_80254CB8(void *, int);
extern void fn_80256638(void *);
extern void fn_80254D68(void *, int);
extern void fn_8025681C(void *);
extern void fn_80254B44(void *, int);
extern void fn_8025111C(void *, int);
extern void fn_802512BC(void *, int);
extern void fn_80251224(void *);
extern u8 lbl_8052D5A8[];
extern const char lbl_8048471C[];
extern const char lbl_80484940[];

void fn_80253A74(Foo *arg0, u32 arg1, Bar *arg2)
{
    switch (arg1) {
    case 9:
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
        if (arg0->unk6C->unk72 == 2 && arg2->unk2 < arg0->unk14 &&
            arg0->unk3D == 0 && arg0->unk9C > arg0->unk9A) {
            arg2->unk6 = (u8)(arg0->unk9C - arg0->unk9A);
            arg0->unk9A = arg0->unk9C;
        } else {
            arg2->unk6 = 0U;
        }
        fn_80254D68(arg0->unk6C, arg0->unkD);
        fn_8025681C(arg0);
        return;
    case 1:
        return;
    case 0:
        fn_80254B44(arg0->unk6C, arg0->unkD);
        return;
    case 2:
        fn_8025111C(arg0->unk6C, arg0->unkD);
        fn_80256638(arg0);
        return;
    case 3:
        arg0->unk68 = 0;
        fn_80254B44(arg0->unk6C, arg0->unkD);
        fn_8025111C(arg0->unk6C, arg0->unkD);
        return;
    case 4:
        fn_802512BC(arg0->unk6C, arg0->unkD);
        return;
    case 5:
        fn_80251224(arg0->unk6C);
        if (lbl_8052D5A8[0x414] >= 1U) {
            fn_80231A14(0x90000, lbl_8048471C, arg0->unk68, (u32)arg1);
        }
        return;
    default:
        if (lbl_8052D5A8[0x414] >= 2U) {
            fn_802319FC(0x90001, lbl_80484940, (u32)arg1);
        }
        return;
    }
}
