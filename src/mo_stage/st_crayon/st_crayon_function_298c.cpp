#pragma force_active on
extern "C" {
void fn_56_1014(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_56_298C(void* p, int del) {
    if (p) {
        fn_56_1014(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
