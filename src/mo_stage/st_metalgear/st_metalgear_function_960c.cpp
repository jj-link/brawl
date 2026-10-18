#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_71_960C(void* p, int n) {
    if (p) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
