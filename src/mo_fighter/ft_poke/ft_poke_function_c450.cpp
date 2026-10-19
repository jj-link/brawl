#pragma force_active on
extern "C" void* fn_116_C2B8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_C450(void* object, short deleting) {
    if (object != 0) {
        fn_116_C2B8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
