#pragma force_active on
extern "C" {
extern void* fn_27_1540CC(void*, short);
extern void __dl__FPv(void*);

void* fn_95_738C(void* ptr, short val) {
    if (ptr) {
        fn_27_1540CC(ptr, -1);
        if (val > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
