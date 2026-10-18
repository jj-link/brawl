#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_110_E05C(void* p, short n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
