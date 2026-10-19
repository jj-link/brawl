#pragma force_active on
extern "C" void fn_50_2034(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_50_39C4(void* p, int n) {
    if (p) {
        fn_50_2034(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
