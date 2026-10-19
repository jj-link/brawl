#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_11AD84(void* p, int flags) {
    if (p) {
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
