#pragma force_active on
extern "C" {
void fn_63_2C40(void* p, int flag);
void __dt__Q28StSeUtil5SeSeqFv(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_63_56AC(void* p, int n) {
    if (p) {
        void* seq = (void*)((char*)p + 0x178);
        if (seq) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        fn_63_2C40(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
