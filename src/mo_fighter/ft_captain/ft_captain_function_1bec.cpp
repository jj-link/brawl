#pragma force_active on
extern "C" void fn_100_1AD0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_1BEC(void* p, short n) {
    if (p) {
        fn_100_1AD0(p, 0);
        if (n > 0)
            __dl__FPv(p);
    }
    return p;
}
