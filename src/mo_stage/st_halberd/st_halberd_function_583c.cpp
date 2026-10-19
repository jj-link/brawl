#pragma force_active on
extern "C" void __dt__Q28StSeUtil5SeSeqFv(void* p, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_57_583C(void* p, int n) {
    if (p) {
        __dt__Q28StSeUtil5SeSeqFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
