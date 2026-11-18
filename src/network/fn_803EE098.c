#include <revolution/OS/OSError.h>
#pragma force_active on
extern int lbl_80599680[];
extern int lbl_805A12C0;
extern void (*lbl_805A12A4)(signed char);
extern char lbl_804931FC[];
extern void fn_803EDF84(void);
extern int fn_803CC930(int, void (*)(void), int *);
extern unsigned char fn_803EEEB4(int, unsigned char *, int);
extern void fn_803D80B0(int);

#pragma opt_common_subs off

int fn_803EE098(int arg0) {
    unsigned char sp8;
    int z;
    if ((arg0 & 2) != 2) return 0;
    lbl_80599680[4] = 0;
    z = lbl_80599680[4];
    if (lbl_80599680[2 + z] != 0) {
        lbl_805A12C0 = 1;
        if (fn_803CC930(lbl_80599680[2], fn_803EDF84, &lbl_805A12C0) != 0)
            OSReport(lbl_804931FC);
    }
    if (lbl_80599680[3 + z] != 0) {
        if (((char *)lbl_80599680)[0x18] == 0 &&
            fn_803EEEB4(lbl_80599680[3], &sp8, 1) == 1)
            ((char *)lbl_80599680)[0x18] = sp8;
        fn_803D80B0(lbl_80599680[3]);
        if (((char *)lbl_80599680)[0x18 + z] != 0 && lbl_805A12A4 != 0)
            lbl_805A12A4(((char *)lbl_80599680)[0x18]);
    }
    return 0;
}
