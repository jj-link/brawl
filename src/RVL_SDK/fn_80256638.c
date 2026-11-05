#pragma force_active on
#include <stdlib.h>
extern unsigned char lbl_8052D5A8[];
extern char lbl_80484B08[];
extern void fn_802319E4(unsigned int, const char *);
extern void fn_802319FC(unsigned int, const char *, int);
extern void fn_80231FB0(void *, int, int);
extern void fn_80232020(void *);
extern void fn_802516E4(void *, int);
extern void fn_80252784(void *, int, int);

void fn_80256638(void *arg0) {
    char *p;
    char *base;
    unsigned char *r30;
    unsigned short i;
    unsigned char count;

    p = (char *)arg0;
    base = lbl_80484B08;
    r30 = *(unsigned char **)(p + 0x6C);

    if (lbl_8052D5A8[0x414] >= 5U) {
        fn_802319E4(0x90004, base + 0x68);
    }
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319E4(0x90003, base + 0x54);
    }
    fn_80232020(p + 0x70);
    p[0x68] = 0;
    if (r30 != NULL) {
        count = p[0x0D];
        *(unsigned char *)(r30 + count + 0x24) = 0;
        p[0x0D] = 0;
        for (i = 0; i < 61; i++) {
            if (r30[i + 0x24] != 0) {
                r30[0x74] = 0;
                goto end;
            }
        }
        if (r30[0x74] != 0) {
            r30[0x74] = 0;
            fn_80252784((void *)r30, 8, 0);
            goto end;
        }
        if (lbl_8052D5A8[0x414] >= 4U) {
            fn_802319FC(0x90003, base + 0x10, 2);
        }
        *(unsigned int *)(r30 + 0x10) = (unsigned int)r30;
        fn_80231FB0((void *)r30, 0xB, 2);
    }
end:
    fn_802516E4(arg0, 0x13);
}