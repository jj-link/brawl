#pragma force_active on
extern "C" {
void fn_801EC158(void*);
int fn_801A91D0();
int fn_801A9D70();
int fn_801AA9D4();
}

extern "C" void fn_801A4D08(int arg0, int arg1, int arg2, int arg3, int arg4) {
    int var_r0;
    if (arg4 == 0) {
        var_r0 = fn_801A91D0() == 0;
    } else if (arg4 == 1) {
        var_r0 = fn_801A9D70() == 0;
    } else {
        var_r0 = fn_801AA9D4() == 0;
    }
    if (var_r0 && arg1) {
        fn_801EC158((void*)arg0);
    }
}
