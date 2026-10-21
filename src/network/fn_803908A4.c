#pragma force_active on
void fn_80390788(void **arg0, int arg1, int arg2);

void fn_803908A4(void **arg0, int arg1) {
    while (*arg0 != 0) {
        fn_80390788(arg0, arg1, ((int *)*arg0)[2]);
    }
}
