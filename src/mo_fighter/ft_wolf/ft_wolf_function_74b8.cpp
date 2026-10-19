#pragma force_active on
extern "C" {
void fn_27_1540CC(void*, short);
void __dl__FPv(void*);
void* fn_125_74B8(void* p, int flag) {
    if (p != 0) {
        fn_27_1540CC(p, -1);
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
