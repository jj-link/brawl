#pragma force_active on

extern "C" {
void* fn_105_1E2C(void* a, short b);
void __dl__FPv(void*);

void* fn_105_1DD0(void* a, short b) {
    if (a != 0) {
        fn_105_1E2C(a, 0);
        if (b > 0) __dl__FPv(a);
    }
    return a;
}
}
