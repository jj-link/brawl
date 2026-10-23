#pragma force_active on
extern "C" {
extern void* fn_27_14FCF4(void*, short);
extern void __dl__FPv(void*);

void* fn_106_2FA0(void* p, short n) {
    if (p != 0) {
        fn_27_14FCF4(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
