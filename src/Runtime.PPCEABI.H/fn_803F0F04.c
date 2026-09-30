// Release a runtime slot when requested, preserving its original pointer.
extern void __dl__FPv(void*);

void* fn_803F0F04(void* slot, int destroy) {
    if (slot != 0 && destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}
