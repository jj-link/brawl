#pragma force_active on
extern "C" {
void fn_801CF9D4(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_801CD318(void* p, int n) {
    if (p) {
        fn_801CF9D4(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
