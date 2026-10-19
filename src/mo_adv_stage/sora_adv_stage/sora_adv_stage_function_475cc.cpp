#pragma force_active on
extern "C" {
void fn_40_43A04(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_40_475CC(void* p, int n) {
    if (p) {
        fn_40_43A04(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
