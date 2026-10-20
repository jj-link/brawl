#pragma force_active on
extern "C" {
void fn_27_23B580(void*, int);
void __dl__FPv(void*);

void* fn_27_23EBC0(void* a, int b) {
    if (a) {
        fn_27_23B580(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
}
