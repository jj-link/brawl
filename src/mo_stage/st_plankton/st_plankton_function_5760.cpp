#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_74_5760(void* p, int n) {
    if (p && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
