#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_73_7B90(void* p, int flag) {
    if (p != 0) {
        __dt__Q28StSeUtil5SeSeqFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
