#pragma force_active on
extern "C" {
void fn_96_20C0(void*, signed short);
void __dl__FPv(void*);
}

extern "C" {
void* fn_96_2124(void* p1, signed short p2) {
    if (p1 != 0) {
        fn_96_20C0(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
}
