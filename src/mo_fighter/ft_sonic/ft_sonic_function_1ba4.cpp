#pragma force_active on
extern "C" void* fn_123_1A8C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_1BA4(void* p, short deleting) {
    short zero = 0;
    if (p != 0) {
        fn_123_1A8C(p, zero);
        if (deleting > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
