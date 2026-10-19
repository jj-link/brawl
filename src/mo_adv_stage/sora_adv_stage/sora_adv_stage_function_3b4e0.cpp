#pragma force_active on
extern "C" void fn_40_24E00(void* p, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_40_3B4E0(void* p, int del) {
    if (p != 0) {
        fn_40_24E00(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
