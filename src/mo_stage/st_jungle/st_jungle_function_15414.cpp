#pragma force_active on
extern "C" {
void fn_51_289C(void* p, int flag);
void __dl__FPv(void* p);

void* fn_51_15414(void* p, int n) {
    if (p) {
        fn_51_289C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
