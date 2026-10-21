#pragma force_active on
extern void *fn_80396EEC(int, int, int);

int fn_8039705C(int a, int b) {
    void *temp_r3;

    temp_r3 = fn_80396EEC(a, b, 0);
    if (temp_r3 != 0) {
        return *(int *)((char *)temp_r3 + 0x10);
    }
    return 0;
}
