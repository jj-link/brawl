#pragma force_active on
extern "C" void* fn_100_3B04(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_3AA8(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_100_3B04(ptr, 0);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
