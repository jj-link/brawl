#pragma force_active on
// Release a runtime allocation when requested, preserving its original pointer.
extern "C" void __dl__FPv(void*);

extern "C" void* fn_801BC480(void* allocation, int destroy) {
    if (allocation != 0 && destroy > 0) {
        __dl__FPv(allocation);
    }
    return allocation;
}
