#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_27_98(void* p, int n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
