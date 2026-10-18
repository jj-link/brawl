#pragma force_active on
extern "C" void fn_100_ADFC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_AE5C(void* ptr, int destroy) {
    if (ptr != 0) {
        fn_100_ADFC((char*)ptr + 4, -1);
        if ((short)destroy > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
