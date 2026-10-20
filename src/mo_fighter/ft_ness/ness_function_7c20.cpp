#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1A15B8(void*, short);
void* fn_101_7C98(void*, short);
}

extern "C" void* fn_101_7C20(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x1FC, static_cast<short>(-1));
        if (object != 0) {
            fn_101_7C98(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
