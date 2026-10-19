#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_3544(void*, short);
void* fn_101_5D14(void*, short);
}

extern "C" void* fn_101_34D4(void* object, short deleting) {
    if (object != 0) {
        fn_101_3544(static_cast<unsigned char*>(object) + 0x8, static_cast<short>(-1));
        fn_101_5D14(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
