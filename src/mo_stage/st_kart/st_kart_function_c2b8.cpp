#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void fn_49_1414(void*, int);
void __dl__FPv(void*);

void* fn_49_C2B8(void* p, int flag) {
    if (p) {
        if ((char*)p + 0x170 != 0) {
            __dt__Q28StSeUtil5SeSeqFv((char*)p + 0x170, 0);
        }
        fn_49_1414(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
