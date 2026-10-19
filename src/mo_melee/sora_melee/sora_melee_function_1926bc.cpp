#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1926BC(void* p, int n) {
    if (p && n > 0)
        __dl__FPv(p);
    return p;
}
