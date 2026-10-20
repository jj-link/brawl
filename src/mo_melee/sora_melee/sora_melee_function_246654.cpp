#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void* fn_27_241EA4(void* p, int flag);
void __dl__FPv(void*);
}

extern "C" void* fn_27_246654(void* p, int flag) {
    if (p) {
        void* seq = (char*)p + 0x78;
        if (seq) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
        }
        fn_27_241EA4(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
