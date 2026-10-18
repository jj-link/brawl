#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_11CF8(void* p, short size) {
    if (p && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
