#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_79_3F8C(void* p, int n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
