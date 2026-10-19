#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_2194(void*, short);
void* fn_101_4030(void*, short);
}

extern "C" void* fn_101_7534(void* object, short deleting) {
    if (object != 0) {
        fn_101_2194(static_cast<unsigned char*>(object) + 0x20, static_cast<short>(0));
        fn_101_4030(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
