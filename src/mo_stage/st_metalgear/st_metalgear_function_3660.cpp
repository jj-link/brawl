#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_71_3660(void* p, int del) {
    if (p) {
        __dt__Q28StSeUtil5SeSeqFv(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
