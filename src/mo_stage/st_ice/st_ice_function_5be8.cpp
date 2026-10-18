#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_62_5BE8(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
