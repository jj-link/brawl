#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_120_3A78(void* p, short n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
