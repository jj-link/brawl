#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_D1908(void* ptr, int destroy) {
    if (ptr != 0) {
        if (destroy > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
