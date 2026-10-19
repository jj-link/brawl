#pragma force_active on
extern "C" {
void fn_27_1362C(void*, short);
void __dl__FPv(void*);

void* fn_91_1A14(void* p, short flag) {
    if (p != 0) {
        fn_27_1362C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
