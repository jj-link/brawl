#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x68];
    u16 field68;
    u8 pad6A[2];
    u8 field6C;
    u8 field6D;
    u8 field6E;
    u8 field6F;
    u8 field70;
} Data;

extern u8 lbl_8052D5A8[];
extern const char lbl_80484664[];
extern const char lbl_804844C0[];

extern void fn_802319FC(int, const char *, u32);
extern void fn_80231A14(u32, const char *, u32, int);
extern u16 fn_8024A530(int, void *);
extern void fn_8024AA7C(u16);
extern void fn_8025047C(Data *, int);
extern void fn_80251184(Data *);
extern void fn_80252768(Data *, u16);
extern void fn_80254B44(Data *, int);
extern void fn_80254BF4(Data *, int, int);
extern void fn_802562B8(Data *);
extern void fn_8022F0E0(u32);

void fn_8025306C(Data *arg0, u32 arg1, u32 arg2)
{
    u16 temp;

    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319FC(0x90003, lbl_80484664, arg1);
    }
    switch (arg1) {
    case 1:
    case 2:
    case 5:
        fn_8024AA7C(arg0->field68);
        if (arg0->field70 != 0) {
            temp = fn_8024A530(3, (void *)((u8 *)arg0 + 0x62));
            arg0->field68 = temp;
            if (temp == 0) {
                fn_8025047C(arg0, 1);
                return;
            }
            fn_80252768(arg0, temp);
            arg0->field70 = 0;
            arg0->field6E = 0;
            arg0->field6F = 0;
            arg0->field6C = 1;
            return;
        }
        fn_802562B8(arg0);
        return;
    case 3:
        fn_80254B44(arg0, 0);
        return;
    case 4:
        fn_8022F0E0(arg2);
        fn_80254BF4(arg0, 0, 0);
        return;
    case 6:
        arg0->field70 = 1;
        return;
    case 14:
        arg0->field6C = 0;
        fn_80251184(arg0);
        return;
    case 8:
        return;
    default:
        if (lbl_8052D5A8[0x414] >= 4U) {
            fn_80231A14(0x90003, lbl_804844C0, arg1, arg0->field6C);
        }
        return;
    }
}
