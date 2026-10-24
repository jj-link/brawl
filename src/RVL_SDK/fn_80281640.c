#pragma force_active on
#pragma use_lmw_stmw on

typedef int s32;

extern s32 fn_802815A0(void *);
extern void fn_80281BBC(s32, s32, s32);

s32 fn_80281640(void *arg0, s32 arg1, s32 arg2)
{
    s32 temp_r31;
    s32 var_r30;
    s32 var_r29;
    s32 var_r31;
    s32 var_r6;
    s32 *p = (s32 *)arg0;

    var_r29 = arg1;
    var_r30 = arg2;
    var_r6 = p[4];
    var_r31 = p[5] - var_r6;

    while (var_r30 > var_r31) {
        fn_80281BBC(p[3] + var_r6, var_r29, var_r31);
        var_r29 += var_r31;
        var_r30 -= var_r31;
        temp_r31 = p[4] + var_r31;
        p[4] = temp_r31;
        if (temp_r31 != fn_802815A0(arg0)) {
            return arg2 - var_r30;
        }
        var_r6 = p[4];
        var_r31 = p[5] - var_r6;
    }

    fn_80281BBC(p[3] + var_r6, var_r29, var_r30);
    p[4] = p[4] + var_r30;
    return arg2;
}
