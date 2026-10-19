#pragma force_active on
extern "C" {
void fn_63_2C40(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_63_14154(void* p, int n) {
    if (p) {
        fn_63_2C40(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
