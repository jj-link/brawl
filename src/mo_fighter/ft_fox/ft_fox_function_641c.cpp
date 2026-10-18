#pragma force_active on
extern "C" void* fn_97_6478(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_641C(void* object, int deleting) {
    if (object != 0) {
        fn_97_6478(object, 0);
        if ((short)deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
