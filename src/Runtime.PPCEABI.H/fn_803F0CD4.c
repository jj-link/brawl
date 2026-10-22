#pragma force_active on
typedef int s32;

void __destroy_arr(char* arg0, void (*arg1)(void*, s32), s32 arg2, s32 arg3) {
    char* var_r31 = arg0 + (arg2 * arg3);
    s32 var_r30 = arg3;

    while (var_r30 != 0) {
        var_r31 -= arg2;
        arg1(var_r31, -1);
        var_r30--;
    }
}
