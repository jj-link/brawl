#pragma force_active on
// Release a runtime allocation when requested, preserving its pointer.
extern "C" {
void __dl__FPv(void*);

void* fn_80174618(void* allocation, int destroy) {
    if (allocation != 0 && destroy > 0) {
        __dl__FPv(allocation);
    }
    return allocation;
}
}
