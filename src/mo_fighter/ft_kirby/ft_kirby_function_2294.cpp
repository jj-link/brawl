#pragma force_active on
extern "C" {
void fn_96_20C0(void*, signed short);
void __dl__FPv(void*);
}

extern "C" void* fn_96_2294(void* p, signed short flag) {
    if (p != 0) {
        fn_96_20C0(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
