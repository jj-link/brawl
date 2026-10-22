#pragma force_active on
extern "C" {
void fn_800B8A0C(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_800F8680(void** p, int n) {
    if (p) {
        fn_800B8A0C(*p, 1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
