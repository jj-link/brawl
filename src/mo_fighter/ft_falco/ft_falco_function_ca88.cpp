#pragma force_active on
extern "C" void* fn_108_4C80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_CA88(void* object, short baseDeleting) {
    if (object != 0) {
        fn_108_4C80(object, 0);
        if (baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
