#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_7EDC4(void* p, int flag) {
    if (p != 0 && flag > 0)
        __dl__FPv(p);
    return p;
}
