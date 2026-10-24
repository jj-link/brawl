#pragma force_active on
extern "C" {
extern void fn_27_1A3A44(void*, short);
extern void __dl__FPv(void*);

void* fn_106_3514(void* p, short n) {
    if (p != 0) {
        fn_27_1A3A44(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
