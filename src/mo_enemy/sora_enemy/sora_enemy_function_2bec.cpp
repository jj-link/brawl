#pragma force_active on
extern "C" void* fn_41_2BAC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2BEC(void* p, short flags) {
    if (p) {
        if (p) {
            fn_41_2BAC(p, 0);
        }
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
