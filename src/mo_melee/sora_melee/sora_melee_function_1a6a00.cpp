#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1A6A00(void* ptr, int count) {
    if (ptr != 0 && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
