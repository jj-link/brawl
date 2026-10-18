#pragma force_active on
// Release a heap block when requested, preserving its original pointer.
extern "C" void __dl__FPv(void* slot);

extern "C" void* fn_100_1DF8(void* slot, short release) {
    if (slot != 0 && release > 0) {
        __dl__FPv(slot);
    }
    return slot;
}
