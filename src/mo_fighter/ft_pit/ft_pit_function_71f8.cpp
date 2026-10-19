#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_71F8(void* p, short flags) {
    if (p != 0) {
        fn_27_C9EDC(p, (short)-1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
