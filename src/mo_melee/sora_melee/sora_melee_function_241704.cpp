#pragma force_active on
extern "C" {

extern void __dl__FPv(void*);
extern void fn_27_24194C(void*, int);

void* fn_27_241704(void* slot, int destroy) {
    if (slot != 0) {
        fn_27_24194C(slot, 0);
        if (destroy > 0) {
            __dl__FPv(slot);
        }
    }
    return slot;
}

}
