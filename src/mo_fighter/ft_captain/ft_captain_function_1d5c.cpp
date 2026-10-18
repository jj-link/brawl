#pragma force_active on
// ft_captain: conditionally release memory, preserving the original pointer.

extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_1D5C(void* slot, short destroy) {
    if (slot != 0 && destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}
