#pragma force_active on
extern "C" void* fn_122_3320(void* object, short deleting);

extern "C" void* fn_122_32C4(void* object, short deleting) {
    if (object != 0) {
        fn_122_3320(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
