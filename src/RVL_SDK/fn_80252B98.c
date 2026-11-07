#pragma force_active on
extern unsigned char lbl_8052D5A8[];
extern char jumptable_80484450[];
extern void fn_802319FC(int, const char *, int);
extern void fn_80231A14(int, const char *, int, int);
extern void fn_80251184(void *);
extern void fn_802531E4(void *, void *);
extern void fn_802532D8(void *, void *);

void fn_80252B98(void *arg0, int arg1, void *arg2)
{
    char *s = jumptable_80484450;
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319FC(0x90003, s + 0xF4, arg1);
    }
    switch (arg1) {
    case 6:
    case 9:
        if (lbl_8052D5A8[0x414] >= 1U) {
            fn_80231A14(0x90000, s + 0x3C, ((unsigned char *)arg0)[0x6C], arg1);
        }
        return;
    case 12:
        fn_802532D8(arg0, arg2);
        return;
    case 11:
        fn_802531E4(arg0, arg2);
        return;
    case 14:
        ((unsigned char *)arg0)[0x6C] = 0;
        fn_80251184(arg0);
        return;
    default:
        if (lbl_8052D5A8[0x414] >= 4U) {
            fn_80231A14(0x90003, s + 0x70, arg1, ((unsigned char *)arg0)[0x6C]);
        }
        return;
    }
}