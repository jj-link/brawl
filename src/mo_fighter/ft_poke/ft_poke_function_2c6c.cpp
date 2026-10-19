#pragma force_active on
extern "C" {
void fn_27_C21DC(void*, short);
void __dl__FPv(void*);

void* fn_116_2C6C(void* p, short flag) {
    if (p != 0) {
        fn_27_C21DC(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
