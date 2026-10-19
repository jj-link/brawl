#pragma force_active on
extern "C" void* fn_96_4DEC(void* p, short flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_96_4E2C(void* p, short flags) {
    if (p != 0) {
        fn_96_4DEC(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
