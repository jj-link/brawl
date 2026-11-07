#pragma force_active on
typedef unsigned char u8;
extern u8 lbl_8052D5A8[];
extern char jumptable_80484450[];
extern void fn_802319FC(int, const char *, int);
extern void fn_80231A14(int, const char *, int, int);
extern void fn_802532D8(void *, void *);
extern void fn_802531E4(void *, void *);
extern void fn_80251184(void *);
extern void fn_802563B4(void *);
extern void fn_8025047C(void *, int);
extern void fn_8024AA7C(unsigned short);

void fn_80252CC0(void *arg0, unsigned int arg1, void *arg2)
{
    char *s = jumptable_80484450;
    if (lbl_8052D5A8[0x414] >= 4U)
        fn_802319FC(0x90003, s + 0x13c, arg1);
    switch (arg1) {
    case 6:
    case 9:
        if (lbl_8052D5A8[0x414] >= 1U)
            fn_80231A14(0x90000, s + 0x3c, ((u8 *)arg0)[0x6c], arg1);
        return;
    case 12:
        fn_802532D8(arg0, arg2);
        return;
    case 11:
        fn_802531E4(arg0, arg2);
        return;
    case 14:
        ((u8 *)arg0)[0x6c] = 0;
        fn_80251184(arg0);
        return;
    case 1:
        fn_802563B4(arg0);
        ((u8 *)arg0)[0x6c] = 5;
        ((u8 *)arg0)[0x71] = 1;
        fn_8025047C(arg0, 0);
        return;
    case 2:
        fn_802563B4(arg0);
    case 5:
        ((u8 *)arg0)[0x6c] = 0;
        fn_8024AA7C(*(unsigned short *)((u8 *)arg0 + 0x68));
        fn_8025047C(arg0, 1);
        return;
    default:
        if (lbl_8052D5A8[0x414] >= 4U)
            fn_80231A14(0x90003, s + 0x70, arg1, ((u8 *)arg0)[0x6c]);
        return;
    }
}