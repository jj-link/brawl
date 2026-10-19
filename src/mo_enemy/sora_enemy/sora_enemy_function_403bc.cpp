#pragma force_active on
extern "C" void* fn_41_40360(void*, short);
extern "C" void* fn_41_33D4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_403BC(void* p, short n) {
    if (p != 0) {
        fn_41_40360((char*)p + 8, -1);
        fn_41_33D4C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
