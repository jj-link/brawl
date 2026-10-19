#pragma force_active on
extern "C" void* fn_116_4150(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_6B20(void* object, short baseDeleting) {
    if (object != 0) {
        fn_116_4150(object, 0);
        if (baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
