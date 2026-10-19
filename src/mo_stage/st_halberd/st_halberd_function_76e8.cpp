#pragma force_active on
extern "C" void __dt__Q28StSeUtil5SeSeqFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_57_76E8(void* p, int shouldDelete) {
    if (p != 0) {
        __dt__Q28StSeUtil5SeSeqFv(p, 0);
        if (shouldDelete > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
