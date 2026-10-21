#pragma force_active on
extern "C" {
void fn_801C4AC8(void **arg0) {
    void *temp_r4 = *arg0;
    if (temp_r4 != 0 && *(void ***)((char *)temp_r4 + 0x1F4) == arg0) {
        *(void ***)((char *)temp_r4 + 0x1F4) = 0;
    }
    if (*arg0 != 0) {
        *arg0 = 0;
    }
}
}
