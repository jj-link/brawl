#pragma force_active on
extern "C" {
void fn_71_276C(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_71_60B0(void* p, int del) {
    if (p != 0) {
        fn_71_276C(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
