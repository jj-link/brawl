#pragma force_active on
extern "C" void* fn_109_10F28(void* ptr, short count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_109_10ECC(void* ptr, short flags) {
    if (ptr != 0) {
        fn_109_10F28(ptr, 0);
        if (flags > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
