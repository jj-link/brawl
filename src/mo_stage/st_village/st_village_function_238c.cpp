#pragma force_active on
extern "C" {
void fn_70_20FC(void* p, int x);
void __dl__FPv(void* p);
}

extern "C" void* fn_70_238C(void* p, int n) {
    if (p != 0) {
        fn_70_20FC(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
