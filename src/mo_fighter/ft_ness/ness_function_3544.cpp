#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_35A0(void*, short);
}

extern "C" void* fn_101_3544(void* object, short deleting) {
    if (object != 0) {
        fn_101_35A0(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
