#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_10570(void* p, short size) {
    if (p != 0) {
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
