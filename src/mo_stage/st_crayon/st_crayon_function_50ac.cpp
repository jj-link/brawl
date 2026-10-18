#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_56_50AC(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
