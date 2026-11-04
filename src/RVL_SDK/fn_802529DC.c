#pragma force_active on
#include <internal/mem.h>

extern unsigned char lbl_8052D5A8[];
extern char jumptable_80484450[];
extern void fn_802319FC(int, const char *, int);
extern void fn_80231A14(int, const char *, int, int);
extern void fn_802319E4(int, const char *);
extern void fn_8025047C(void *, unsigned short);
extern void fn_80251184(void *);
extern void fn_8024AA7C(unsigned short);
extern void fn_8024A8F4(unsigned short, void *);

void fn_802529DC(void *arg0, int arg1, unsigned short *arg2)
{
    char *s = jumptable_80484450;
    unsigned char data[0x3C];

    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319FC(0x90003, s + 0xCC, arg1);
    }
    switch (arg1) {
    case 6:
        if (lbl_8052D5A8[0x414] >= 1U) {
            fn_80231A14(0x90000, s + 0x3C, ((unsigned char *)arg0)[0x6C], arg1);
        }
        return;
    case 9:
        if ((int)*arg2 != 0) {
            ((unsigned char *)arg0)[0x6C] = 0;
            fn_8025047C(arg0, *arg2);
            return;
        }
        ((unsigned char *)arg0)[0x6C] = 2;
        if (lbl_8052D5A8[0x414] >= 4U) {
            fn_802319E4(0x90003, s + 0x58);
        }
        memset(data, 0, 0x3C);
        data[2] = 1;
        *(unsigned short *)(data + 4) = 0x69B;
        data[0x20] = 0;
        data[6] = 0;
        fn_8024A8F4(*(unsigned short *)((unsigned char *)arg0 + 0x68), data);
        return;
    case 14:
        ((unsigned char *)arg0)[0x6C] = 0;
        fn_80251184(arg0);
        return;
    case 5:
        ((unsigned char *)arg0)[0x6C] = 0;
        fn_8024AA7C(*(unsigned short *)((unsigned char *)arg0 + 0x68));
        fn_80251184(arg0);
        return;
    default:
        if (lbl_8052D5A8[0x414] >= 4U) {
            fn_80231A14(0x90003, s + 0x70, arg1, ((unsigned char *)arg0)[0x6C]);
        }
        return;
    }
}
