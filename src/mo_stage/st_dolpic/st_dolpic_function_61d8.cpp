#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_46_61D8(void* p, int n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
