#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
extern void fn_96_20C0(void*, signed short);
}

extern "C" void* fn_96_21DC(void* ptr, signed short release) {
    if (ptr != 0) {
        fn_96_20C0(ptr, 0);
        if (release > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
