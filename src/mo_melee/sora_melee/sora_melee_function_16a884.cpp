#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_16A884(void* p, int n) {
    if (p && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
