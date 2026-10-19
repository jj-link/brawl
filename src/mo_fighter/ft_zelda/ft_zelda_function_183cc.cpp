#pragma force_active on
extern "C" void fn_27_1A0CAC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_183CC(void* p, short n) {
    short m = -1;
    if (p != 0) {
        fn_27_1A0CAC(p, m);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
