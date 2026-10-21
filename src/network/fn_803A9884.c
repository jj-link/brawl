#pragma force_active on
typedef unsigned char u8;

u8 *fn_803A9884(u8 *arg0, u8 *arg1)
{
    u8 temp_r5;
    u8 *var_r6;

    var_r6 = arg0;
    goto check;

loop:
    arg1++;
    var_r6++;

check:
    temp_r5 = *arg1;
    *var_r6 = temp_r5;
    if ((signed char)temp_r5 != 0) {
        goto loop;
    }
    return arg0;
}
