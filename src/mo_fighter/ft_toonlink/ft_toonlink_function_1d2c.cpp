#pragma force_active on
extern "C" void fn_121_1BB4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_1D2C(void* p, short n) {
    if (p) {
        fn_121_1BB4(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
