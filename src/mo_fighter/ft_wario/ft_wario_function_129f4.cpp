#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_110_129F4(void* p, short flags) {
    if (p != 0 && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
