#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void __dl__FPv(void*);

void* fn_78_7D00(void* p, int flag) {
    if (p) {
        __dt__Q28StSeUtil5SeSeqFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
