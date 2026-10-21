#pragma force_active on
// Release a slot when requested, preserving its original pointer.
extern "C" {
void __dl__FPv(void*);

void* fn_800AAA98(void* slot, int destroy) {
    if (slot != 0 && destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}
}
