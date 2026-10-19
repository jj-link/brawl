#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_7C514(void* p, int size) {
    if (p && size > 0)
        __dl__FPv(p);
    return p;
}
