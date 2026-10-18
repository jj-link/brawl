#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_64D5C(void* p, int size) {
    if (p != 0 && size > 0)
        __dl__FPv(p);
    return p;
}
