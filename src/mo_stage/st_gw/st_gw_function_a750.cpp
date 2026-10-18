#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_63_A750(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
