#pragma force_active on
extern "C" void* fn_123_1A8C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_1B48(void* p1, short p2) {
    if (p1 != 0) {
        short z = 0;
        fn_123_1A8C(p1, z);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
