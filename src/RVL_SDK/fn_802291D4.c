#pragma force_active on
extern void fn_801D76BC(void *, unsigned int);
extern void fn_80228E98(int, int, int, int, int, int, int, int);

void fn_802291D4(int a0, int a1, int a2, int a3, int a4, int a5) {
    fn_801D76BC((void *)a3, a2);
    fn_80228E98(a0, a1, a2, a3, 2, a4, a5, 1);
}
