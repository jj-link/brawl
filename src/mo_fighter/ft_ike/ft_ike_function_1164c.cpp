#pragma force_active on
extern "C" void* fn_119_1160C(void* p, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_1164C(void* p, short s) {
    void* r = p;
    if (p != 0) {
        short z = 0;
        fn_119_1160C(p, z);
        if (s > 0) {
            __dl__FPv(p);
        }
    }
    return r;
}
