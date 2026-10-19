#pragma force_active on
extern "C" void fn_40_2A5D0(void* p, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_40_2C2D8(void* p, int size) {
    if (p != 0) {
        fn_40_2A5D0(p, 0);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
