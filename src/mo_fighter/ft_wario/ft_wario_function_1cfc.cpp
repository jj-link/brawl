#pragma force_active on
extern "C" {
extern void fn_110_1BE0(void*, short);
extern void __dl__FPv(void*);

void* fn_110_1CFC(void* ptr, short flag) {
    if (ptr != 0) {
        fn_110_1BE0(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
