#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_27_C4434(void* p, long release) {
    if (p && release > 0)
        __dl__FPv(p);
    return p;
}
}
