#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_16FC4(void* object, int deleting) {
    if (object != 0) {
        fn_27_C9EDC(object, (short)-1);
        if ((short)deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
