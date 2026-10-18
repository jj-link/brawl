#pragma force_active on
extern "C" void* fn_27_1A2D10(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1AD00(void* p, short memberDeleting) {
    if (p != 0) {
        fn_27_1A2D10(p, -1);
        if (memberDeleting > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
