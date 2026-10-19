#pragma force_active on
extern "C" void fn_110_1BE0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_1CA0(void* ptr, short destroy) {
    if (ptr != 0) {
        fn_110_1BE0(ptr, 0);
        if (destroy > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
