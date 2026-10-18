#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_125C4(void* slot, short release) {
    if (slot != 0 && release > 0) {
        __dl__FPv(slot);
    }
    return slot;
}
