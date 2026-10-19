#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void __dl__FPv(void*);

void* fn_50_8968(void* p, int n) {
    if (p) {
        __dt__Q28StSeUtil5SeSeqFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
