#pragma force_active on
void operator delete(void*);

extern "C" void* fn_123_1A8C(void* object, short deleting);

extern "C" void* fn_123_1D14(void* object, short deleting) {
    if (object != 0) {
        fn_123_1A8C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
