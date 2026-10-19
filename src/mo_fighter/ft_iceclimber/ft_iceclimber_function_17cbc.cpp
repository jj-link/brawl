#pragma force_active on
extern "C" void* fn_105_17D18(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_105_17CBC(void* p, short n) {
    if (p != 0) {
        fn_105_17D18(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
