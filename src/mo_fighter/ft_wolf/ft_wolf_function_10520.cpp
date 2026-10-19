#pragma force_active on
extern "C" void* fn_125_45C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_10520(void* p, short n) {
    if (p != 0) {
        fn_125_45C8(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
