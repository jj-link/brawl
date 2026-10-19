#pragma force_active on
extern "C" void fn_27_234C8C(void* self, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_40_DE4C(void* p, int del) {
    if (p != 0) {
        fn_27_234C8C(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
