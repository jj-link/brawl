#pragma force_active on
extern "C" {
void __dl__FPv(void* p);
void* fn_110_10014(void* p, short flag);

void* fn_110_FFB8(void* p, short flag) {
    if (p) {
        fn_110_10014(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
