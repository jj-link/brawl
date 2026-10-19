#pragma force_active on
extern "C" void fn_27_1540CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_6198(void* p, short flags) {
    if (p != 0) {
        fn_27_1540CC(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
