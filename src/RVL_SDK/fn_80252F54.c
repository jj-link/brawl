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
} Data;

extern u8 lbl_8052D5A8[];
extern char lbl_80484610[];
extern char lbl_804844C0[];

extern void fn_802319FC(u32, const char *, int);
extern void fn_80231A14(u32, const char *, int, int);
extern void fn_8024AA7C(u16);
extern void fn_80251184(Data *);
extern void fn_80254B44(Data *, int);
extern void fn_80254CB8(Data *, int);
extern void fn_80256340(Data *, int);

void fn_80252F54(Data *arg0, int arg1)
{
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319FC(0x90003, lbl_80484610, arg1);
    }
    switch (arg1) {
    case 5:
    case 8:
        fn_80256340(arg0, 3);
        arg0->field6C = 6;
        fn_80254CB8(arg0, 0);
        break;
    case 14:
        arg0->field6C = 0;
        fn_80251184(arg0);
        break;
    case 3:
        fn_80254B44(arg0, 0);
        if (arg0->field6D != 0) {
            fn_8024AA7C(arg0->field68);
        }
        fn_80251184(arg0);
        break;
    default:
        if (lbl_8052D5A8[0x414] >= 4U) {
            fn_80231A14(0x90003, lbl_804844C0, arg1, arg0->field6C);
        }
        break;
    }
}
