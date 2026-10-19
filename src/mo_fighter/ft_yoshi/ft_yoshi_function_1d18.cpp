#pragma force_active on
extern "C" {
extern void fn_95_1C58(void*, short);
extern void __dl__FPv(void*);

void* fn_95_1D18(void* a, short b) {
    if (a != 0) {
        fn_95_1C58(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
}
