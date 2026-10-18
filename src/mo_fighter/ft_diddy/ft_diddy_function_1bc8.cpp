#pragma force_active on
extern "C" void fn_115_1B08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1BC8(void* p1, int p2) {
    if (p1 != 0) {
        fn_115_1B08(p1, 0);
        if ((short)p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
