#pragma force_active on
typedef unsigned char u8;
typedef signed short s16;

extern "C" void* fn_41_54474(void* p1, short p2);
extern "C" void* fn_41_33D4C(void* p, short n);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_544D8(void* p, s16 n) {
    if (p != 0) {
        fn_41_54474(static_cast<u8*>(p) + 8, -1);
        fn_41_33D4C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
