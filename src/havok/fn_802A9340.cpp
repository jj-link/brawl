#pragma force_active on
// Release a runtime allocation when requested, preserving its original pointer.
// The original vector destructor checks the element count (arg1) and, when the
// buffer pointer is non-NULL and the count is positive, frees the buffer via
// __dl__FPv before handing the original pointer back to the caller.
extern "C" {
void __dl__FPv(void*);
void* __dt__14Class_802A9340Fv(void*, int);
}

extern "C" void* __dt__14Class_802A9340Fv(void* allocation, int destroy) {
    if (allocation != 0 && destroy > 0) {
        __dl__FPv(allocation);
    }
    return allocation;
}
