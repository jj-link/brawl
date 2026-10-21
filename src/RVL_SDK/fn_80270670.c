#pragma force_active on
// Release a runtime slot when requested, preserving its original pointer.
extern void __dl__FPv(void*);

void* fn_80270670(void* slot, int destroy) {
    if (slot != 0 && destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}
