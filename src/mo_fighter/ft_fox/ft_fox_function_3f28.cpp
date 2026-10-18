#pragma force_active on
extern "C" {

extern void __dl__FPv(void*);

void* fn_97_3F28(void* slot, short destroy) {
    if (slot != 0 && destroy > 0) {
        __dl__FPv(slot);
    }
    return slot;
}

}
