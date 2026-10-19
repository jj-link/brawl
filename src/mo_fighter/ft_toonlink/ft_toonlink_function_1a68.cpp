#pragma force_active on
extern "C" {
void fn_27_1362C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_121_1A68(void* slot, short destroying) {
    if (slot != 0) {
        fn_27_1362C(slot, 0);
        if (destroying > 0) {
            __dl__FPv(slot);
        }
    }
    return slot;
}
