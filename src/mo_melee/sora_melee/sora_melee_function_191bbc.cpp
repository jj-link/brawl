#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_191BBC(void* p, int size) {
    if (p != 0) {
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
