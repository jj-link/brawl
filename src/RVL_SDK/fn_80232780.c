#pragma force_active on
void fn_8022F0E0(void *);

void fn_80232780(void **arg0) {
    void *temp_r0;

    temp_r0 = *arg0;
    if (temp_r0 != 0) {
        fn_8022F0E0(temp_r0);
        *arg0 = 0;
    }
}
