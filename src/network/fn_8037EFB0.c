#pragma force_active on
extern void *fn_8037C720();

void fn_8037EFB0(void *unused, int value) {
    void *temp_r3;

    temp_r3 = fn_8037C720();
    if (temp_r3 != 0) {
        *(int *)((char *)temp_r3 + 0x184) = value;
    }
}
