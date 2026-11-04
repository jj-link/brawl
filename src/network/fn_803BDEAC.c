#include <types.h>
#pragma force_active on

extern char lbl_8053B248[];
extern char lbl_8059FE68;
extern char lbl_8059FE6C;
extern char lbl_8059FE70;

extern char *fn_803A9884(char *dst, char *src);
extern s32 fn_803A98A8(char *a, char *b);
extern u32 fn_803A9A78(void *p);
extern char *fn_803A9AA8(void *p, u32 idx);
extern s32 fn_803BDB18(char *a, char *b, s32 *c);
extern s32 fn_803BFA8C(void *p, s32 a, s32 b);

s32 fn_803BDEAC(char *arg0, void *arg1, s32 arg2) {
    char spC[0x1C];
    s32 sp8;
    char *var_r31;
    char *temp_r30;

    sp8 = 0;
    var_r31 = spC;
    temp_r30 = fn_803A9AA8(arg1, 3);
    fn_803A9884(var_r31, arg0);
    if (((*(u32 *)(lbl_8053B248 + 0x3c)) & 2) == 2 && fn_803A9A78(arg1) == 2 && fn_803A98A8(spC, &lbl_8059FE68) != 0 && fn_803A98A8(spC, &lbl_8059FE6C) != 0 && fn_803BFA8C(arg1, 3, 1) == 0 && arg2 == 0) {
        return 1;
    }
    if (fn_803A98A8(temp_r30, &lbl_8059FE70) == 0) {
        while (*var_r31 != 0 && *var_r31 != '.') {
            var_r31++;
        }
        if (*var_r31 == 0) {
            var_r31[0] = '.';
            var_r31[1] = 0;
        }
    } else {
        if (*temp_r30 == 0) {
            return 1;
        }
        if (spC[0] == 0) {
            return 1;
        }
    }
    return fn_803BDB18(spC, temp_r30, &sp8);
}
