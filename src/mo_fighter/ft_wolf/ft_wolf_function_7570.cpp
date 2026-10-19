#pragma force_active on
extern "C" {
void fn_27_64D9C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_125_7570(void* p, short s) {
    if (p) {
        fn_27_64D9C(p, -1);
        if (s > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
