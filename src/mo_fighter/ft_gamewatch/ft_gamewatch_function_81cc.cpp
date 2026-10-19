#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_81CC(void* p0, short size) {
    if (p0 != 0) {
        fn_27_C9EDC(p0, (short)-1);
        if (size > 0) {
            __dl__FPv(p0);
        }
    }
    return p0;
}
