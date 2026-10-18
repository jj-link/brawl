#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_40_1D768(void* ptr, int destroy) {
    if (ptr != 0 && destroy > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
