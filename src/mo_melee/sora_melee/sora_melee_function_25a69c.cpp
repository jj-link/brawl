#pragma force_active on
extern "C" void* fn_27_241EA4(void* p, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_25A69C(void* p, int flag) {
    if (p) {
        if (p) {
            fn_27_241EA4(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
