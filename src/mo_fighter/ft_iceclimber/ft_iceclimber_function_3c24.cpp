#pragma force_active on
extern "C" void* fn_105_3C80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_3C24(void* slot, int destroy) {
    if (slot != 0) {
        short d = (short)destroy;
        fn_105_3C80(slot, 0);
        if (d > 0) {
            __dl__FPv(slot);
        }
    }
    return slot;
}
