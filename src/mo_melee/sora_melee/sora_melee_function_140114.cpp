#pragma force_active on
// Release a dynamically allocated block when requested, preserving its original pointer.
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_140114(void* ptr, int release) {
    if (ptr != 0 && release > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
