#pragma force_active on
extern void fn_80231FB0(void *p, int a, int b);
extern void *fn_8024E73C(void);

void fn_8024D4F4(void) {
    int *temp_r3;

    temp_r3 = (int *)fn_8024E73C();
    if (temp_r3 != 0 && temp_r3[2] == 0) {
        fn_80231FB0((char *)temp_r3 + 0x10, 2, 0x78);
    }
}
