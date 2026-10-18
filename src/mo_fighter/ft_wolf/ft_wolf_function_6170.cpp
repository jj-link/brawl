#pragma force_active on
// Release a dynamically allocated block when requested, preserving the pointer.
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_6170(void* ptr, short release) {
    if (ptr != 0) {
        if (release > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
