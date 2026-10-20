#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_F500(void*, short);
void* fn_101_F3D0(void*, short);
}

extern "C" void* fn_101_F560(void* object, short deleting) {
    if (object != 0) {
        fn_101_F500(static_cast<unsigned char*>(object) + 0x94, static_cast<short>(-1));
        if (object != 0) {
            fn_101_F3D0(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
