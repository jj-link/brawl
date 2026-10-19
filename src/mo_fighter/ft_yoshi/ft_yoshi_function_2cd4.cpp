#pragma force_active on
extern "C" void* fn_27_14CD30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_2CD4(void* p, short flags) {
    if (p != 0) {
        fn_27_14CD30(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
