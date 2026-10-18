#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_107_134CC(void* slot, short destroy) {
    if (slot != 0 && destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}
}
