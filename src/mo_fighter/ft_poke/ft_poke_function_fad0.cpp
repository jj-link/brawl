#pragma force_active on
extern "C" void* fn_27_1A0FA4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_FAD0(void* p, int count) {
    if (p != 0) {
        fn_27_1A0FA4(p, (short)-1);
        if ((short)count > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
