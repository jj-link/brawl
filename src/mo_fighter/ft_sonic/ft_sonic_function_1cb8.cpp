#pragma force_active on
void operator delete(void*);

extern "C" void fn_123_1A8C(void*, short);

extern "C" void* fn_123_1CB8(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = 0;
        fn_123_1A8C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
