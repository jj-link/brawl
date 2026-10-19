#pragma force_active on
extern "C" {
void* fn_96_1FE4(void* p, short n);
void __dl__FPv(void* p);
}

extern "C" void* fn_96_2024(void* p, short n) {
    if (p != 0) {
        fn_96_1FE4(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
