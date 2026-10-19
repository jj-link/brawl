#pragma force_active on
extern "C" void* fn_109_3BAC(void* ptr, short flag);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_109_3B50(void* ptr, short flag) {
    if (ptr != 0) {
        fn_109_3BAC(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
