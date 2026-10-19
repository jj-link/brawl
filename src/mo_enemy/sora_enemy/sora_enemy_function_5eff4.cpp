#pragma force_active on
typedef signed short s16;
typedef unsigned char u8;

extern "C" void* fn_41_5EF90(void* p1, short p2);
extern "C" void* fn_41_33D4C(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_5EFF4(void* p1, s16 p2) {
    if (p1 != 0) {
        s16 m1 = -1;
        s16 z = 0;
        fn_41_5EF90((u8*)p1 + 8, m1);
        fn_41_33D4C(p1, z);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
