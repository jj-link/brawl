#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_8015DFE0(void* slot, int destroy) {
    if (slot != 0 && destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}
}
