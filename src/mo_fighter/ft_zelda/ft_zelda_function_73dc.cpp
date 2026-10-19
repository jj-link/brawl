#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_73DC(void* p, short flag) {
    if (p != 0) {
        fn_27_C9EDC(p, (short)-1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
