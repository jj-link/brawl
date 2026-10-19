#pragma force_active on
extern "C" void* fn_27_3544C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_259C(void* object, short deleting) {
    if (object != 0) {
        fn_27_3544C(object, -1);
        if ((short)deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
