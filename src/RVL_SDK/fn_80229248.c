#pragma force_active on
void fn_801D76BC(void* addr, unsigned long nBytes);
void fn_80228E98(int a, int b, int c, int d, int e, int f, int g, int h);

void fn_80229248(int a0, int a1, int a2, int a3, int a4, int a5) {
    fn_801D76BC((void*)a3, a2);
    fn_80228E98(a0, a1, a2, a3, 1, a4, a5, 1);
}
