#pragma force_active on
extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void fn_71_276C(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_71_4CB4(void* p, int flag) {
    if (p != 0) {
        void* seq_addr = (char*)p + 0x198;
        if (seq_addr != 0) {
            __dt__Q28StSeUtil5SeSeqFv(seq_addr, 0);
        }
        if (p != 0) {
            fn_71_276C(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
