#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_3B0C(void*, short);

extern "C" void* fn_101_207D0(void* object, short deleting) {
    if (object != 0) {
        int unused;
        (void)unused;
        if (object != 0) {
            fn_101_3B0C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
