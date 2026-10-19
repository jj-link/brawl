#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_27_C7770(void* slot, short destroy) {
    if (slot != 0 && destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}
}
