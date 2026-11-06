#pragma force_active on
extern unsigned char lbl_8052CDC0[];
extern char jumptable_80483008[];
extern void fn_802319FC(int, void *, int);
extern void fn_8024FA74(void *);
extern void fn_8024F4F8(int, unsigned char, unsigned short, unsigned short);
extern void fn_8022F0E0(void *);

void fn_8024BEC8(void *arg0, unsigned short arg1, void *arg2)
{
    char *a = (char *)arg0;
    void *r7 = *(void **)(a + 0x30);
    char *jt = jumptable_80483008;
    void (*fp2)(unsigned short, unsigned short) =
        *(void (**)(unsigned short, unsigned short))((char *)r7 + 0x1C);
    void (*fp1)(unsigned short, unsigned short) =
        *(void (**)(unsigned short, unsigned short))((char *)r7 + 0x18);
    unsigned short val = *(unsigned short *)(a + 0x14);

    if (lbl_8052CDC0[0] >= 4) {
        fn_802319FC(0x80003, jt + 0x6B0, arg1);
    }

    switch (arg1) {
    case 3:
        if (lbl_8052CDC0[0] >= 3) {
            fn_802319FC(0x80002, jt + 0x40,
                        *(unsigned short *)(a + 0x14));
        }
        fn_8024FA74(arg0);
        fp1(val, 0);
        break;

    case 18:
        fn_8024FA74(arg0);
        if (fp2 != 0) {
            if (lbl_8052CDC0[0] >= 3) {
                fn_802319FC(0x80002, jt + 0x6D8, val);
            }
            fp2(val, 0);
        }
        break;

    case 17:
        fn_8024F4F8(*(int *)(a + 0x10),
                    *(unsigned char *)(a + 0x36),
                    *(unsigned short *)(a + 0x14),
                    *(unsigned short *)(a + 0x16));
        fn_8024FA74(arg0);
        if (fp2 != 0) {
            if (lbl_8052CDC0[0] >= 3) {
                fn_802319FC(0x80002, jt + 0x6D8, val);
            }
            fp2(val, 0);
        }
        break;

    case 30:
        fn_8024FA74(arg0);
        if (fp2 != 0) {
            if (lbl_8052CDC0[0] >= 3) {
                fn_802319FC(0x80002, jt + 0x6D8, val);
            }
            fp2(val, 0xEEEE);
        }
        break;

    case 19:
    case 29:
        fn_8022F0E0(arg2);
        break;

    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    default:
        break;
    }
}
