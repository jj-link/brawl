#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_61_A238(void* p, int flags) {
    if (p != 0) {
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
