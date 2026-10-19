#pragma force_active on
extern "C" void fn_56_1014(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_56_19E4(void* p, int destroy) {
    if (p != 0) {
        fn_56_1014(p, 0);
        if (destroy > 0)
            __dl__FPv(p);
    }
    return p;
}
