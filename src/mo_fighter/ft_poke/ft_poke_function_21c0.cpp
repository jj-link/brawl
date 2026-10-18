#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
void* fn_116_21C0(void* slot, short destroy);
}

extern "C" void* fn_116_21C0(void* slot, short destroy) {
    if (slot != 0) {
        if (destroy > 0) {
            __dl__FPv(slot);
        }
    }
    return slot;
}
