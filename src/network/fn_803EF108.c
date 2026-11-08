#pragma force_active on
extern int fn_801C8B20(void* obj);
extern void fn_803EF1F0(void* self);

int fn_803EF108(void** arg0, void* arg1) {
    int var_r31 = 0;
    if (arg1 != 0 && fn_801C8B20(arg1) != 0) {
        fn_803EF1F0(arg0);
        *arg0 = arg1;
        var_r31 = 1;
    }
    return var_r31;
}
