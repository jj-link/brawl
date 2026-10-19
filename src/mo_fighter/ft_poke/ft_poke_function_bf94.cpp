#pragma force_active on
extern "C" {
void fn_116_3844(void*, short);
void __dl__FPv(void*);

void* fn_116_BF94(void* p, short flag) {
    if (p != 0) {
        fn_116_3844(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
