#pragma force_active on
extern "C" void fn_125_1B84(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_1D58(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_125_1B84(ptr, 0);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
