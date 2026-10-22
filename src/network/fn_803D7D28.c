#pragma force_active on
extern int fn_803EC3D4(int);
extern int fn_803EC418(int);
extern void fn_803D8994(int, int);

int fn_803D7D28(void *arg0, int arg1) {
    int temp_r31;
    int *temp_r5;

    if (fn_803EC3D4(*(int *)((char *)arg0 + 0x14)) != 0) {
        return 0x14;
    }
    temp_r5 = *(int **)((char *)arg0 + 0x4);
    temp_r31 = ((int (*)(void *, int))temp_r5[4])(arg0, arg1);
    if (fn_803EC418(*(int *)((char *)arg0 + 0x14)) != 0) {
        return 0x14;
    }
    if (temp_r31 != 0) {
        fn_803D8994(*(int *)((char *)arg0 + 0x2C), temp_r31);
        return 0x15;
    }
    return 0;
}
