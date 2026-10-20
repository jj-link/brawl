#pragma force_active on

extern "C" {
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void* fn_71_276C(void* p, int flag);
void __dl__FPv(void*);

void* fn_71_36B8(void* p, int flag) {
    if (p != 0) {
        void* seq = (char*)p + 0x1b8;
        if (seq != 0) {
            __dt__Q28StSeUtil5SeSeqFv(seq, 0);
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
}
