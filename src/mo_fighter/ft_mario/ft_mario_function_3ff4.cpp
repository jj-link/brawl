#pragma force_active on
extern "C" {
void* fn_91_19B8(void*, short);
void* fn_91_1A14(void*, short);

void* fn_91_3FF4(void* object, short deleting) {
    if (object != 0) {
        fn_91_19B8(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(0));
        fn_91_1A14(static_cast<unsigned char*>(object) + 8, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
