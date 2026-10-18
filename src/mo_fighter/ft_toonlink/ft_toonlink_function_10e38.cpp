#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_10E38(void* slot, unsigned short destroy) {
    if (slot != 0 && (short)destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}