#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_FD4C(void*, short);
}

extern "C" void* fn_101_FDC4(void* object, short deleting) {
    if (object != 0) {
        fn_101_FD4C(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
