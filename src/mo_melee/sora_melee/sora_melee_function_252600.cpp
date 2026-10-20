#pragma force_active on
extern "C" {
void fn_27_248FA8(void* a, int b);
void __dl__FPv(void* a);

void* fn_27_252600(void* a, int b) {
    if (a != 0) {
        fn_27_248FA8(a, 0);
        if (b > 0)
            __dl__FPv(a);
    }
    return a;
}
}
