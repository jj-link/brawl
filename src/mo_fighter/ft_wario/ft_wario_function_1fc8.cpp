#pragma force_active on
extern "C" void fn_27_7700(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_1FC8(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_27_7700(ptr, 0);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
