#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_D8(void*, int);

extern "C" void* fn_27_1C28(void* r3, int r4) {
    if (r3) {
        fn_27_D8(r3, 0);
        if (r4 > 0)
            __dl__FPv(r3);
    }
    return r3;
}
