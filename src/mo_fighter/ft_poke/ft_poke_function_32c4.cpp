#pragma force_active on
typedef short s16;

extern "C" void* fn_116_3320(void* object, s16 deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_116_32C4(void* object, s16 deleting) {
    if (object != 0) {
        fn_116_3320(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
