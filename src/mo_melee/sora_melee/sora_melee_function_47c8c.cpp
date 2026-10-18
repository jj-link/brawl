#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_47C8C(void* p, int n) {
    if (p) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
