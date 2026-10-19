#pragma force_active on
extern "C" {
void fn_27_269CA4(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_40_23E68(void* p, int del) {
    if (p) {
        fn_27_269CA4(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
