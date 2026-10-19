#pragma force_active on
extern "C" void fn_800C2BB4(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_40_436B8(void* p, int del) {
    if (p) {
        fn_800C2BB4(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
