#pragma force_active on
extern "C" {
extern void __dl__FPv(void* p);

void* fn_110_15550(void* p, short n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
