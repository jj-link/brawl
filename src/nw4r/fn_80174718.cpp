#pragma force_active on
// Release an allocation when requested, preserving its pointer.
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_80174718(void* allocation, int destroy) {
    if (allocation != 0 && destroy > 0) {
        __dl__FPv(allocation);
    }
    return allocation;
}
}
