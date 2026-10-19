#pragma force_active on
extern "C" {
void fn_91_9738(void*, short);

void* fn_91_CBBC(void* object, short deleting) {
    if (object != 0) {
        fn_91_9738(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
