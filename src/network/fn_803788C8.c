#pragma force_active on

typedef signed int s32;

extern char *SOInetNtoA(s32 *);
extern int sprintf(char *s, const char *fmt, ...);
extern char lbl_80535A40[0x40];
extern s32 lbl_805A1050;
extern char lbl_8059F990[6];
extern char lbl_8059F998[3];
extern char lbl_8059F99C[4];

char *fn_803788C8(s32 arg0, s32 arg1, char *arg2) {
    s32 spC;
    s32 sp8;
    s32 temp_r6;
    char *var_r31;

    if (arg2 != 0) {
        var_r31 = arg2;
    } else {
        temp_r6 = lbl_805A1050 ^ 1;
        lbl_805A1050 = temp_r6;
        var_r31 = lbl_80535A40 + temp_r6 * 0x16;
    }
    if (arg0 != 0) {
        if (arg1 != 0) {
            spC = arg0;
            sprintf(var_r31, lbl_8059F990, SOInetNtoA(&spC), arg1);
        } else {
            sp8 = arg0;
            sprintf(var_r31, lbl_8059F998, SOInetNtoA(&sp8));
        }
    } else if (arg1 != 0) {
        sprintf(var_r31, lbl_8059F99C, arg1);
    } else {
        *var_r31 = 0;
    }
    return var_r31;
}
