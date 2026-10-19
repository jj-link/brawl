#pragma force_active on
extern "C" {
void fn_67_20BC(void* p, int flag);
void __dl__FPv(void* p);

void* fn_67_A084(void* p, int doFree) {
    if (p) {
        fn_67_20BC(p, 0);
        if (doFree > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
