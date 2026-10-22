#pragma force_active on
typedef int s32;

s32 PFSTR_InitStr(void *, s32, s32);
s32 fn_803E5694(void *, s32, s32 *);
s32 fn_803EB3BC(s32);
s32 fn_803EB4EC(s32, s32);
extern char lbl_805644C0[];

s32 fn_803EB644(s32 arg0, s32 arg1) {
    char sp10[0x10];
    s32 sp8;
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = fn_803EB3BC(arg1);
    if (temp_r3 == 0) {
        *(s32 *)(lbl_805644C0 + 0x40) = 0xA;
        return 0;
    }
    temp_r3_2 = PFSTR_InitStr(sp10, arg0, 1);
    if (temp_r3_2 == 0) {
        temp_r3_2 = fn_803E5694(sp10, temp_r3, &sp8);
    } else {
        *(s32 *)(lbl_805644C0 + 0x40) = temp_r3_2;
    }
    return fn_803EB4EC(temp_r3_2, sp8);
}
