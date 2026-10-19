#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_A0C34(void* p, int shouldDelete) {
    if (p != 0 && shouldDelete > 0)
        __dl__FPv(p);
    return p;
}
