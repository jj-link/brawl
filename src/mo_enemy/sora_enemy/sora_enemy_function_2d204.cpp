#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_41_2D204(void* p, short mode) {
    if (p != 0 && mode > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
