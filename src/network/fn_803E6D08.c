#include <types.h>
#pragma force_active on

extern char lbl_805644C0[];
extern char lbl_8059FEE8;
extern char lbl_8059FEEC;
extern char lbl_8059FEF0;

extern char *fn_803D645C(char *dst, char *src);
extern s32 fn_803D6480(char *a, char *b);
extern u32 fn_803D66F4(void *p);
extern char *fn_803D6724(void *p, u32 idx);
extern s32 fn_803E6974(char *a, char *b, s32 *c);
extern s32 fn_803E88BC(void *p, s32 a, s32 b);

s32 fn_803E6D08(char *arg0, void *arg1, s32 arg2) {
    char spC[0x1C];
    s32 sp8;
    char *var_r31;
    char *temp_r30;

    sp8 = 0;
    var_r31 = spC;
    temp_r30 = fn_803D6724(arg1, 3);
    fn_803D645C(var_r31, arg0);
    if (((*(u32 *)(lbl_805644C0 + 0x60)) & 2) == 2 && fn_803D66F4(arg1) == 2 && fn_803D6480(spC, &lbl_8059FEE8) != 0 && fn_803D6480(spC, &lbl_8059FEEC) != 0 && fn_803E88BC(arg1, 3, 1) == 0 && arg2 == 0) {
        return 1;
    }
    if (fn_803D6480(temp_r30, &lbl_8059FEF0) == 0) {
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
    return fn_803E6974(spC, temp_r30, &sp8);
}
