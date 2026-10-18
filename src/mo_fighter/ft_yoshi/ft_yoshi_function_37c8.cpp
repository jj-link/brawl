#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_37C8(void* p, int count) {
    if (p && (short)count > 0)
        __dl__FPv(p);
    return p;
}
