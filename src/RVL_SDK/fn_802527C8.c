#pragma force_active on
extern void fn_802319E4(int, void *);
extern void fn_802319FC(int, void *, int);
extern void fn_80231A14(int, void *, int, int);
extern unsigned short fn_8024A530(int, void *);
extern void fn_8024A764(void *, unsigned char, unsigned short, int, int);
extern void fn_8024A8F4(unsigned short, void *);
extern void fn_8025047C(void *, int);
extern void fn_80252768(void *, unsigned short);
extern void fn_80254BF4(void *, int, int);
extern void fn_80256340(void *, int);
extern void *memset(void *, int, unsigned long);
extern unsigned char lbl_8052D5A8[];
extern char jumptable_80484450[];
void fn_802527C8(unsigned char *arg0, unsigned int arg1, unsigned char *arg2)
{
    unsigned char buf[0x3C];
    unsigned short temp;
    char *jt = jumptable_80484450;
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319FC(0x90003, jt + 0x1C, arg1);
    }
    switch (arg1) {
    case 6:
        *(unsigned short *)(arg0 + 0x6A) = 0x29A;
        temp = fn_8024A530(3, arg0 + 0x62);
        *(unsigned short *)(arg0 + 0x68) = temp;
        if (temp == 0) {
            fn_8025047C(arg0, 1);
            return;
        }
        fn_80252768(arg0, temp);
        arg0[0x6C] = 1;
        return;
    case 7:
    case 9:
    case 11:
    case 12:
        if (lbl_8052D5A8[0x414] >= 1U) {
            fn_80231A14(0x90000, jt + 0x3C, arg0[0x6C], arg1);
        }
        return;
    case 10:
        if (arg0[0x6D] != 0) {
            fn_8024A764(arg0 + 0x62, arg2[0], *(unsigned short *)(arg0 + 0x68), 1, 0);
            return;
        }
        fn_80256340(arg0, 0x78);
        fn_8024A764(arg0 + 0x62, arg2[0], *(unsigned short *)(arg0 + 0x68), 0, 0);
        if (lbl_8052D5A8[0x414] >= 4U) {
            fn_802319E4(0x90003, jt + 0x58);
        }
        memset(buf, 0, 0x3C);
        buf[2] = 1;
        *(unsigned short *)(buf + 4) = 0x69B;
        buf[0x20] = 0;
        buf[6] = 0;
        fn_8024A8F4(*(unsigned short *)(arg0 + 0x68), buf);
        arg0[0x6C] = 2;
        return;
    case 1:
    case 2:
        return;
    case 3:
        fn_80254BF4(arg0, 0, 1);
        return;
    case 4:
        fn_80254BF4(arg0, 0, 0);
        return;
    default:
        if (lbl_8052D5A8[0x414] >= 4U) {
            fn_80231A14(0x90003, jt + 0x70, arg1, arg0[0x6C]);
        }
        break;
    }
}