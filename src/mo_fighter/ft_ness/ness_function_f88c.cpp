#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_101_F82C(void*, short);
void* fn_101_F6F8(void*, short);
}

extern "C" void* fn_101_F88C(void* object, short deleting) {
    if (object != 0) {
        fn_101_F82C(static_cast<unsigned char*>(object) + 0x134, static_cast<short>(-1));
        if (object != 0) {
            fn_101_F6F8(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
