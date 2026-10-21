#pragma force_active on
extern "C" {
    void __dl__FPv(void*);

    void* fn_801B48D8(void* slot, int destroy) {
        if (slot != 0 && destroy > 0) {
            __dl__FPv(slot);
        }
        return slot;
    }
}
