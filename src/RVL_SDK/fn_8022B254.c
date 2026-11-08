#include <revolution/OS/OSAlarm.h>
#pragma force_active on
extern unsigned char lbl_804FB4A0[];
extern unsigned int lbl_805A0674;
extern long long fn_801E1B54(void);
extern unsigned int fn_8020E18C(void);
extern void fn_8022B438(void);
extern void fn_8022AF34(void);
extern void fn_8022D2D0(void);
extern int fn_80234B00(int);

void fn_8022B254(void) {
    unsigned char state;
    unsigned char *p = lbl_804FB4A0;
    switch (p[0x10]) {
    case 1:
        state = 1;
        if ((int)(500 - ((unsigned int)fn_801E1B54() - lbl_805A0674) / ((*(unsigned int*)0x800000F8 / 4) / 1000)) < 0 && fn_8020E18C() != 1) {
            fn_8022B438();
            state = 2;
        }
        p[0x10] = state;
        break;
    case 2:
        fn_8022AF34();
        break;
    case 4:
        OSCancelAlarm((OSAlarm*)(p + 0x710));
        p[0x708] = 1;
        fn_80234B00((int)fn_8022D2D0);
        p[0x10] = 5;
        break;
    }
}