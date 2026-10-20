#pragma force_active on
extern "C" {

extern void __dl__FPv(void*);
void fn_27_245538(void*, int);

void* fn_27_245718(void* slot, int destroy) {
    if (slot != 0) {
        fn_27_245538(slot, 0);
        if (destroy > 0) {
            __dl__FPv(slot);
        }
    }
    return slot;
}

}
