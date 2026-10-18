#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_63_9D80(void* p, int size) {
    if (p != 0) {
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
