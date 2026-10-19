#pragma force_active on
extern "C" {
void fn_27_2726B4(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_40_3314C(void* p, int n) {
    if (p) {
        fn_27_2726B4(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
