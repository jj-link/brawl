#pragma force_active on
extern "C" void fn_20_254(void* self, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_20_B0A4(void* p, int n) {
    if (p) {
        fn_20_254(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
