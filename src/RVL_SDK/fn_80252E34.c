#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_802319FC(int, const char *, int);
extern void fn_80231A14(u32, const char *, int, int);
extern void fn_802505DC(void *);
extern void fn_80251184(u32);
extern void fn_80254B44(void *, int);
extern void fn_80254BF4(void *, int, int);
extern unsigned char lbl_8052D5A8[];
extern const char lbl_804844C0[];
extern const char lbl_804845EC[];

void fn_80252E34(void *arg0, int arg1, u16 *arg2)
{
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319FC(0x90003, lbl_804845EC, arg1);
    }
    switch (arg1) {
    case 14:
        ((u8 *)arg0)[0x6C] = 0;
        fn_80251184((u32)arg0);
        return;
    case 0:
        fn_802505DC(arg0);
        return;
    case 7:
        if ((int)*arg2 != 0) {
            fn_80254BF4(arg0, 0, 1);
            return;
        }
        fn_80254B44(arg0, 0);
        ((u8 *)arg0)[0x6C] = 5;
        ((u8 *)arg0)[0x71] = 1;
        return;
    default:
        if (lbl_8052D5A8[0x414] >= 4U) {
            fn_80231A14(0x90003, lbl_804844C0, arg1, ((u8 *)arg0)[0x6C]);
        }
        return;
    }
}
