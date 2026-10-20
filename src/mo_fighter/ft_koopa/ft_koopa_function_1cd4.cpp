#pragma force_active on
extern "C" {
void fn_102_1AA4(void* p, short v);
void __dl__FPv(void* p);

void* fn_102_1CD4(void* p, short flag) {
    if (p != 0) {
        fn_102_1AA4(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
