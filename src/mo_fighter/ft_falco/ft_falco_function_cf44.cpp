#pragma force_active on
extern "C" void* fn_108_CDAC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_CF44(void* object, short deleting) {
    if (object != 0) {
        fn_108_CDAC(object, 0);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
