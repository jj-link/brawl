#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_27_342ED4(void* p, int n) {
    if (p && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
