#include <string.h>
#pragma force_active on

extern void fn_80335638(int, const char *, ...);
extern void fn_80335450(int, int, int);
extern void fn_80385CC4(void);
extern void fn_803895D0(void *);
extern char lbl_8048B7A0[];
extern int lbl_805A0F90;
extern int lbl_805A0F98;
extern int lbl_805A0F9C;
extern int lbl_805A0FA0;
extern int lbl_805A0FA4;
extern int lbl_805A0FA8;
extern int lbl_805338B0[];

void fn_80342A90(void) {
    int i;
    int *p;

    fn_80335638(0x40, lbl_8048B7A0);
    if (lbl_805A0FA8 != 0) {
        if (*(int *)(lbl_805A0FA8 + 0xf8) != 0) {
            if (lbl_805A0F98 == 0) {
                fn_803895D0(*(void **)(lbl_805A0FA8 + 0xf8));
                *(int *)(lbl_805A0FA8 + 0xf8) = 0;
            } else {
                lbl_805A0F9C = 1;
            }
        }
        if (lbl_805A0FA0 == 0) {
            fn_80385CC4();
        } else {
            lbl_805A0FA4 = 1;
        }
        *(int *)(lbl_805A0FA8 + 0x1b4) = 0;
        if (lbl_805A0F90 != 0) {
            fn_80335450(4, lbl_805A0F90, 0);
            lbl_805A0F90 = 0;
        }
        i = 0;
        p = lbl_805338B0;
        do {
            if (p[1] != 0) {
                fn_80335450(4, p[1], 0);
            }
            i++;
            p += 3;
        } while (i < 0x9A);
        memset(lbl_805338B0, 0, 0x738);
        *(char *)(lbl_805A0FA8 + 0x2c) = 1;
    }
}