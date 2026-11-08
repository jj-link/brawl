#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern s32 lbl_8059FCE0;
extern s32 lbl_805A1170;
extern s32 lbl_805A1174;
extern s32 lbl_805A1178;
extern s32 lbl_805A117C;
extern s32 lbl_805A1180;

void OSRegisterVersion(s32);
s32 fn_80399760(void);
s32 fn_8039B60C(void);
void fn_8039D4E4(s32);
s32 fn_803A0DE4(void);
void fn_803A0EC4(void);
s32 fn_803A1CA0(void);
s32 fn_803A1ED4(void);
s32 fn_803A494C(void);
s32 fn_803C2F08(void);

s32 fn_8039A028(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 var_r31;
    s32 var_r3;
    u32 var_r0;
    u32 var_r0_2;
    u32 var_r30;

    lbl_805A117C = 0;
    if (fn_803C2F08() == 0) {
        return -1;
    }
    if (lbl_805A1174 == 1) {
        return -0xA;
    }
    if (lbl_805A1174 == 3) {
        return -0x1A;
    }
    if (arg0 == 0) {
        return -5;
    }
    if (arg0 & 0x1F) {
        return -0x17;
    }
    var_r3 = fn_803A0DE4();
    if (var_r3 == 0) {
        if (lbl_805A1180 == 0) {
            OSRegisterVersion(lbl_8059FCE0);
            lbl_805A1180 = 1;
        }
        lbl_805A1170 = arg0;
        lbl_805A1178 &= 0xFFFFFFFE;
        fn_8039D4E4(arg0 + 0x1900);
        var_r30 = 0;
        var_r31 = 0;
        temp_r3 = fn_80399760();
        if (temp_r3 != 0) {
            var_r31 = temp_r3;
            var_r30 |= 4;
        }
        temp_r3_2 = fn_8039B60C();
        if (temp_r3_2 != 0) {
            var_r31 = temp_r3_2;
            var_r30 |= 4;
        }
        temp_r3_3 = fn_803A1CA0();
        if (temp_r3_3 != 0) {
            var_r31 = temp_r3_3;
            var_r30 |= 4;
        }
        temp_r3_4 = fn_803A1ED4();
        if (temp_r3_4 != 0) {
            var_r31 = temp_r3_4;
            var_r0 = var_r30 | 1;
            if (temp_r3_4 == -0x14) {
                var_r0 = var_r30 | 4;
            }
            var_r30 = var_r0;
        }
        temp_r3_5 = fn_803A494C();
        if (temp_r3_5 < 0) {
            var_r31 = temp_r3_5;
            var_r0_2 = var_r30 | 2;
            if (temp_r3_5 == -0x14) {
                var_r0_2 = var_r30 | 4;
            }
            var_r30 = var_r0_2;
        }
        if (var_r30 == 3) {
            var_r31 = -0x31;
        }
        if (var_r30 != 0) {
            lbl_805A1170 = 0;
            fn_803A0EC4();
            var_r3 = var_r31;
            goto block_32;
        }
        lbl_805A1174 = arg1;
        return 0;
    }
block_32:
    switch (var_r3) {
    case -49:
    case -46:
    case -43:
    case -42:
    case -38:
    case -29:
    case -26:
    case -22:
    case -21:
    case -20:
    case -19:
    case -18:
    case -17:
    case -16:
    case -14:
    case -1:
        lbl_805A117C = var_r3 + 0xFFFE5638;
        break;
    }
    return var_r3;
}
