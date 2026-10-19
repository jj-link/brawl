#pragma force_active on
extern "C" {
void* fn_27_1A4368(void* p, short n);
void __dl__FPv(void*);

void* fn_110_5228(void* p, short n) {
    if (p != 0) {
        fn_27_1A4368(p, (short)-1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
