#pragma force_active on
extern "C" void fn_56_1014(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_56_14D4(void* ptr, int count) {
    if (ptr != 0) {
        fn_56_1014(ptr, 0);
        if (count > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
