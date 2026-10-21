#pragma force_active on
// Release a runtime slot when requested, preserving its original pointer.
extern "C" {
void __dl__FPv(void*);

void* fn_800469E4(void* slot, int destroy) {
    if (slot != 0 && destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}
}
