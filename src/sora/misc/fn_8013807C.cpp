#pragma force_active on
// Release a runtime allocation when requested, preserving its pointer.
extern "C" {
extern void __dl__FPv(void*);

void* fn_8013807C(void* p, int destroy);
}

void* fn_8013807C(void* p, int destroy) {
    if (p != 0 && destroy > 0) {
        __dl__FPv(p);
    }
    return p;
}
