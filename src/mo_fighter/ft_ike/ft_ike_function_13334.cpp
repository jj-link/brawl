#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_13334(void* p, short flags) {
    if (p != 0 && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
