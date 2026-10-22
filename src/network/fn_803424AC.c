#include <string.h>
#pragma force_active on

extern void fn_80335450(int, int, int);
extern int lbl_805A0F90;
extern void* lbl_805A0FA8;
extern int lbl_805338B0[];

void fn_803424AC(void) {
    int i;
    int* p;

    lbl_805A0FA8 = 0;
    if (lbl_805A0F90) {
        fn_80335450(4, lbl_805A0F90, 0);
        lbl_805A0F90 = 0;
    }

    i = 0;
    p = lbl_805338B0;
    do {
        if (p[1]) {
            fn_80335450(4, p[1], 0);
        }
        i++;
        p += 3;
    } while (i < 0x9A);

    memset(lbl_805338B0, 0, 0x738);
}
