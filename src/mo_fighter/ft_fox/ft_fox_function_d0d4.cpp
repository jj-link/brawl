#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_97_CF3C(void*, short);

extern "C" void* fn_97_D0D4(void* object, short deleting) {
    if (object != 0) {
        fn_97_CF3C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
