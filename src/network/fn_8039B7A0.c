#include <types.h>
#pragma force_active on

extern char *fn_80399A58(void);
extern s32 fn_80397664(char *arg0, u32 arg1);
extern void fn_80397DE0(s32 arg0, char *arg1, ...);
extern char lbl_8059FCE8[5];
extern char lbl_80491CA8[14];
extern char lbl_80491CB8[14];

s32 fn_8039B7A0(s32 arg0, s32 arg1, s32 arg2) {
    char *temp;

    temp = fn_80399A58();
    if (arg2 < fn_80397664(temp, 0x40) + 0xE) {
        return -0xB;
    }
    switch (arg0) {
    case 0:
        fn_80397DE0(arg1, lbl_8059FCE8, temp, lbl_80491CA8);
        break;
    case 1:
        fn_80397DE0(arg1, lbl_8059FCE8, temp, lbl_80491CB8);
        break;
    default:
        return -3;
    }
    return 0;
}
