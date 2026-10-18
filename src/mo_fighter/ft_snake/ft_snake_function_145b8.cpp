#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_145B8(void* p, short n) {
    if (p && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
