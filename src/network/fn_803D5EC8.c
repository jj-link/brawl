#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern s32 fn_803CD270(void);
extern s32 fn_803D50C4(s32, s32);
extern s32 fn_803D521C(s32);
extern s32 fn_803D577C(s32, s32, u32, s32);
extern s32 fn_803D5924(s32, s32, u32);
extern void fn_803D5B78(s32, s32);
extern s32 fn_803D5B90(s32);

s32 fn_803D5EC8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;

    var_r31 = arg3;
    if (fn_803CD270() == 0) {
        return 1;
    }
    switch (arg1) {
    case 0:
        var_r31 = fn_803D50C4(arg0, var_r31);
        break;
    case 1:
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (fn_803D577C(arg0, arg1 - 2, var_r31 & 0xFF, 0) != 0) {
            var_r31 = 0;
        } else {
            var_r31 = 7;
        }
        break;
    case 7:
        if (fn_803D5924(arg0, arg2, var_r31) != 0) {
            var_r31 = 0;
        } else {
            var_r31 = 7;
        }
        break;
    case 6:
        fn_803D5B78(arg0, var_r31);
        var_r31 = 0;
        break;
    }
    if (var_r31 == 0) {
        if (fn_803D521C(arg0 + 0x46) == 0) {
            var_r31 = 7;
        } else if (fn_803D5B90(arg0) == 0) {
            var_r31 = 7;
        }
    }
    return var_r31;
}
