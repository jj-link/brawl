#pragma force_active on
// Release a runtime allocation when requested, preserving its original pointer.
extern "C" {
void __dl__FPv(void*);
void* fn_801C108C(void* allocation, int destroy);
}

void* fn_801C108C(void* allocation, int destroy) {
    if (allocation != 0 && destroy > 0) {
        __dl__FPv(allocation);
    }
    return allocation;
}
