#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_C74E8(void*, short);
void* fn_101_1B9C(void*, short);
}

extern "C" void* fn_101_CEF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_27_C74E8(members + 0x4AE10, static_cast<short>(-1));
        fn_101_1B9C(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
