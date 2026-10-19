#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_2B1368(void* ptr, int size) {
    if (ptr != 0 && size > 0)
        __dl__FPv(ptr);
    return ptr;
}
