#pragma force_active on
extern "C" {
void fn_41_402F0(void* a, short b);
void __dl__FPv(void* a);

void* fn_41_40360(void* a, short b) {
    if (a != 0) {
        fn_41_402F0(a, 0);
        if (b > 0)
            __dl__FPv(a);
    }
    return a;
}
}
