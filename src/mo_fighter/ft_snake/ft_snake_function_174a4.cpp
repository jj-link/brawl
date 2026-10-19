#pragma force_active on
extern "C" {
void fn_27_1A4C8C(void* p, short size);
void __dl__FPv(void* p);

void* fn_122_174A4(void* p, short flag) {
    if (p) {
        fn_27_1A4C8C(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
