#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void fn_78_17D0(void*, int);
void __dl__FPv(void*);

void* fn_78_7D58(void* p, int flag) {
    if (p) {
        char* seq = (char*)p + 0x170;
        if (seq) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        fn_78_17D0(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
