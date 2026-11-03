#pragma force_active on
extern "C" {
void fn_8015C238(void*, int);
void fn_8018BCB0(void*, int);
void __dl__FPv(void*);

void* fn_8018C07C(void* p, int flag) {
    if (p) {
        void* seq = (void*)((char*)p + 0x24);
        if (seq) {
            fn_8015C238(seq, 0);
        }
        fn_8018BCB0(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}