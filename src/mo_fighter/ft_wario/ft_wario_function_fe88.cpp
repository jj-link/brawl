#pragma force_active on
extern "C" void* fn_110_451C(void* p, short n);

extern "C" void* fn_110_FE88(void* p, short n) {
    if (p != 0) {
        fn_110_451C(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
