#pragma force_active on
#include <types.h>

extern "C" {

extern u32 lbl_27_bss_64A0[0xB2];
extern const s16 lbl_27_rodata_53A0[];

s32 fn_27_2A117C(s32 arg0, s32 arg1) {
    s16* var_r3;
    s16 temp_r0;
    s32 temp_r3;
    s32 temp_r6;
    s32 var_r4;

    temp_r6 = arg1 * 4;
    temp_r3 = *(s32*)((char*)lbl_27_bss_64A0 + temp_r6);
    if (temp_r3 != 0) {
        return (temp_r3 - 1) == 0;
    }
    var_r4 = 0;
    var_r3 = (s16*)((char*)lbl_27_rodata_53A0 + arg1 * 0xE);
    goto check;
loop_body:
    if (temp_r0 == -2) {
        *(u32*)((char*)lbl_27_bss_64A0 + temp_r6) = 1;
        return 1;
    }
    var_r3 += 1;
    var_r4 += 1;
check:
    if (var_r4 >= 7) {
        goto done;
    }
    temp_r0 = *var_r3;
    if (temp_r0 == -1) {
        goto done;
    }
    goto loop_body;
done:
    *(u32*)((char*)lbl_27_bss_64A0 + temp_r6) = 2;
    return 0;
}

}
