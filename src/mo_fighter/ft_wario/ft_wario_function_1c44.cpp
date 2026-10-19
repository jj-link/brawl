#pragma force_active on
extern "C" {

extern void __dl__FPv(void*);
extern void fn_110_1BE0(void*, short);

void* fn_110_1C44(void* slot, short destroy) {
    if (slot != 0) {
        fn_110_1BE0(slot, 0);
        if (destroy > 0) {
            __dl__FPv(slot);
        }
    }
    return slot;
}

}
