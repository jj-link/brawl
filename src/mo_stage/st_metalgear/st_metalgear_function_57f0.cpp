#pragma force_active on
extern "C" void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void operator delete(void* p);

extern "C" void* fn_71_57F0(void* p, int n) {
    if (p) {
        __dt__Q28StSeUtil5SeSeqFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
