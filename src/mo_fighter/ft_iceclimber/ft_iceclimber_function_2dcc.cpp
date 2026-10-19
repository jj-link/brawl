#pragma force_active on
extern "C" void* fn_27_19816C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_2DCC(void* object, int deleting) {
    if (object != 0) {
        fn_27_19816C(object, -1);
        if ((short)deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
