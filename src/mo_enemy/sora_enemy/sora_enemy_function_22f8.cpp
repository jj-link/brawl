#pragma force_active on
typedef signed short s16;
extern "C" void fn_27_D53A8(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_22F8(void* p, s16 flags) {
    if (p != 0) {
        fn_27_D53A8(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
