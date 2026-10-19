#pragma force_active on
extern "C" void fn_41_5943C(void*, short);
extern "C" void* fn_41_33D4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_594A0(void* p, short n) {
    if (p != 0) {
        fn_41_5943C((char*)p + 8, -1);
        fn_41_33D4C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
