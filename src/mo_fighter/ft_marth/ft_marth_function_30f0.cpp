#pragma force_active on
extern "C" {
void* fn_27_19874C(void*, short);
void __dl__FPv(void*);
void* fn_106_30F0(void* p, short n) {
    if (p != 0) {
        fn_27_19874C(p, static_cast<short>(-1));
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}