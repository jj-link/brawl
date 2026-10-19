#pragma force_active on
extern "C" void* fn_41_3E600(void* p, short flags);
extern "C" void* fn_41_33D4C(void* p, short n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_3E664(void* p, short flags) {
    if (p) {
        fn_41_3E600((char*)p + 8, -1);
        fn_41_33D4C(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
