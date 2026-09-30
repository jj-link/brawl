// Release a runtime allocation when requested, preserving its pointer.
extern void __dl__FPv(void*);

void* fn_803F11A0(void* allocation, int destroy) {
    if (allocation != 0 && destroy > 0) {
        __dl__FPv(allocation);
    }
    return allocation;
}
