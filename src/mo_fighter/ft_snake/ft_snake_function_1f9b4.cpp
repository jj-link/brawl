#pragma force_active on
extern "C" void* fn_122_1F974(void* p, short flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_122_1F9B4(void* p, short flags) {
    if (p != 0) {
        fn_122_1F974(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
