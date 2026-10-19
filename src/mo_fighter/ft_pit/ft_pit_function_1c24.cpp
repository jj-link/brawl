#pragma force_active on
extern "C" {
void fn_112_1B64(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_112_1C24(void* a, short b) {
    if (a != 0) {
        fn_112_1B64(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
