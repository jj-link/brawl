#pragma force_active on
extern "C" void* fn_41_3CE88(void* p1, short p2);
extern "C" void* fn_41_33D4C(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_3CEEC(void* p1, short p2) {
    if (p1 != 0) {
        fn_41_3CE88((char*)p1 + 8, -1);
        fn_41_33D4C(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
