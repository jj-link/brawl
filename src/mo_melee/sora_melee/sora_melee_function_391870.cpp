#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_391870(void* p, int size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
