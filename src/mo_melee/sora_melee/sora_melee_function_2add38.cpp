#pragma force_active on
extern "C" {
    extern void __dl__FPv(void*);

    void* fn_27_2ADD38(void* slot, int destroy) {
        if (slot != 0 && destroy > 0) {
            __dl__FPv(slot);
        }
        return slot;
    }
}
