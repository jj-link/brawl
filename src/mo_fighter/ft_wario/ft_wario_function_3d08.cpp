#pragma force_active on
extern "C" void* fn_110_3D64(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_110_3D08(void* p, int count) {
    if (p != 0) {
        fn_110_3D64(p, 0);
        if ((short)count > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
