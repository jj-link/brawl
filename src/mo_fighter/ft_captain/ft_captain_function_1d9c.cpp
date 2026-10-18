#pragma force_active on

extern "C" void* fn_100_1DF8(void* slot, short release);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_1D9C(void* slot, short release) {
    if (slot != 0) {
        fn_100_1DF8(slot, 0);
        if (release > 0) {
            __dl__FPv(slot);
        }
    }
    return slot;
}
