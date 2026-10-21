#pragma force_active on
// Release a runtime allocation when requested, preserving its pointer.
// Matches fn_801C88C0 (main, 0x801C88C0, 64 bytes).
//
// Behavior: if the pointer is non-NULL and the 'destroy' flag is strictly
// positive, the allocation is handed to the runtime destructor helper
// __dl__FPv.  The original pointer is always returned so callers can keep
// using the handle they passed in.
extern "C" void __dl__FPv(void*);

extern "C" void* fn_801C88C0(void* ptr, int destroy) {
    if (ptr != 0 && destroy > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
