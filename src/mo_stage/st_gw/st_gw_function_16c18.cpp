#pragma force_active on
extern "C" {
void fn_63_2C40(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_63_16C18(void* p, int n) {
    if (p != 0) {
        fn_63_2C40(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
