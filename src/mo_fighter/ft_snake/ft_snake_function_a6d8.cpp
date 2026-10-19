#pragma force_active on
extern "C" void* fn_122_A734(void* object, short deleting);

extern "C" void* fn_122_A6D8(void* object, short deleting) {
    if (object != 0) {
        fn_122_A734(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
