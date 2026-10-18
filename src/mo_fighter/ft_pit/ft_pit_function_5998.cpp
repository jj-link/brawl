#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_112_5998(void* p, short size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
