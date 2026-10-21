#pragma force_active on
// Release an allocation when requested, preserving its original pointer.
extern "C" void __dl__FPv(void*);

extern "C" void* fn_801746D8(void* ptr, int count) {
    if (ptr != 0 && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
