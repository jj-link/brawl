#pragma force_active on
extern "C" {
extern void fn_27_1362C(void*, short);
extern void __dl__FPv(void*);

void* fn_106_1F40(void* p, short n) {
    if (p != 0) {
        fn_27_1362C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
