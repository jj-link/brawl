#pragma force_active on

typedef int s32;
typedef unsigned short u16;

extern s32 fn_803B8524(char *, u16);
extern s32 fn_803B900C(void);
extern s32 fn_803B9584(void);

s32 fn_803B83A0(char *arg0, s32 arg1, s32 *arg2) {
    s32 temp_r0;
    s32 var_r3;

    temp_r0 = *(s32 *)(arg0 + 0x1C);
    switch (temp_r0) {
    case 0:
        var_r3 = fn_803B8524(arg0, (u16)arg1);
        break;
    case 1:
        var_r3 = fn_803B900C();
        break;
    case 2:
        var_r3 = fn_803B9584();
        break;
    default:
        var_r3 = 0xF;
        *arg2 = -1;
        break;
    }
    return var_r3 & ((-var_r3 | var_r3) >> 31);
}
