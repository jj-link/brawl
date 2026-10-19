#pragma force_active on
extern "C" {
void fn_96_20C0(void*, signed short);
void __dl__FPv(void*);

void* fn_96_234C(void* p, signed short flags) {
    if (p != 0) {
        fn_96_20C0(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
