#pragma force_active on
extern "C" void fn_120_1B3C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_1AE0(void* ptr, short flag) {
    if (ptr != 0) {
        fn_120_1B3C(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
