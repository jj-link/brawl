#pragma force_active on
extern "C" {
extern void __dl__FPv(void*, int);

void* fn_27_318D84(void* a, int b) {
    if (a && b > 0)
        __dl__FPv(a, b);
    return a;
}
}
