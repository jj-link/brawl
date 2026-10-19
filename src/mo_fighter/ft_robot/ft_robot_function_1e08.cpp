#pragma force_active on
extern "C" void* fn_120_1E64(void* p, short flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_120_1E08(void* p, short flags) {
    if (p != 0) {
        fn_120_1E64(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
