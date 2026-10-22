#pragma force_active on
typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

extern "C" s32 fn_8027DD18(s32);
extern "C" s32 fn_8027DD5C(s32, s32);
extern "C" s32 fn_8027DD78(s32, s32);
extern "C" s32 fn_8027DD98(s32, s32);
extern "C" u32 fn_8027DDE0(s32, s32);
extern "C" void fn_8027DDFC(s32, s32, s32);

extern "C" void fn_803317DC(s32 arg0, s32 arg1) {
    s32 temp_r31;
    s32 var_r30;

    var_r30 = fn_8027DD18(arg1 + 8);
    while ((s8)(fn_8027DDE0(arg1 + 8, var_r30) >> 24) != 0) {
        temp_r31 = fn_8027DD78(arg1 + 8, var_r30);
        fn_8027DDFC(arg0 + 8, fn_8027DD5C(arg1 + 8, var_r30), temp_r31);
        var_r30 = fn_8027DD98(arg1 + 8, var_r30);
    }
}
