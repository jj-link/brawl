#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_385394(void* ptr, int release) {
    if (ptr != 0 && release > 0)
        __dl__FPv(ptr);
    return ptr;
}
