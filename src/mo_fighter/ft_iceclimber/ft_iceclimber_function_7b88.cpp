#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_7B88(void* object, short deleting) {
    if (object != 0) {
        fn_27_C9EDC(object, (short)-1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
