#pragma force_active on
extern "C" void fn_51_3C30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_51_10980(void* p, int n) {
    if (p) {
        fn_51_3C30(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
