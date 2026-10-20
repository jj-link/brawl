#pragma force_active on
extern "C" {
void fn_27_27C580(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_27_231CA8(void* p, int v) {
    if (p) {
        fn_27_27C580(p, 0);
        if (v > 0)
            __dl__FPv(p);
    }
    return p;
}
