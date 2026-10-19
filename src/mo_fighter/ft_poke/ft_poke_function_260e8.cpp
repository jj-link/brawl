#pragma force_active on
extern "C" void* fn_116_26144(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_260E8(void* object, short deleting) {
    if (object != 0) {
        fn_116_26144(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
