#pragma force_active on
extern "C" {
void* fn_27_241EA4(void* p, int flag);
void __dl__FPv(void* p);

void* fn_27_25912C(void* p, int flag) {
    if (p) {
        if (p) {
            fn_27_241EA4(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
