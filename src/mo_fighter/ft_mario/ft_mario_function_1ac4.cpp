#pragma force_active on
extern "C" {
void* fn_91_1A84(void* object, short deleting);
void* fn_91_1AC4(void* object, short deleting) {
    if (object != 0) {
        fn_91_1A84(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
