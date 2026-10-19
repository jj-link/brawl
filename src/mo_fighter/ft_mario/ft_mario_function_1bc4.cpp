#pragma force_active on
extern "C" {
void* fn_91_1B60(void*, short);
void* fn_91_1BC4(void* object, short deleting) {
    if (object != 0) {
        fn_91_1B60(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
