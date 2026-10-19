#pragma force_active on
extern "C" void __dt__Q28StSeUtil5SeSeqFv(void* p, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" {
void* fn_54_E70C(void* p, int flag) {
    if (p) {
        __dt__Q28StSeUtil5SeSeqFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
