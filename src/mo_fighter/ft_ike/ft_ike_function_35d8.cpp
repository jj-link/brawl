#pragma force_active on
extern "C" void* fn_119_3634(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_119_35D8(void* p, short n) {
    if (p != 0) {
        fn_119_3634(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
