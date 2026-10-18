#pragma force_active on
extern "C" void* fn_100_12DB4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_12D58(void* ptr, int flag) {
    if (ptr != 0) {
        fn_100_12DB4(ptr, 0);
        if ((short)flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
