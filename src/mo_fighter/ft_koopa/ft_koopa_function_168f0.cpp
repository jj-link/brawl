#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_168F0(void* p, short n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
