#pragma force_active on
extern "C" void* fn_94_4750(void* p, short flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_94_D8A8(void* p, short flags) {
    if (p != 0) {
        fn_94_4750(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
