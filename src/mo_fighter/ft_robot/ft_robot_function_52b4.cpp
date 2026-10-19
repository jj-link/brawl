#pragma force_active on
extern "C" void* fn_120_5310(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_52B4(void* p, short flags) {
    if (p != 0) {
        fn_120_5310(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
