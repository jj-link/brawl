#pragma force_active on
// Release an allocated buffer when requested, preserving its original pointer.
extern "C" {
extern void __dl__FPv(void*);

void* fn_27_C3B58(void* ptr, int count);
}

extern "C" void* fn_27_C3B58(void* ptr, int count) {
    if (ptr != 0 && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
