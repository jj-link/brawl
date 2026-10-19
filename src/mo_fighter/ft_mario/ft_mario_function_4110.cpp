#pragma force_active on
extern "C" {
void* fn_91_4060(void*, short);
void* fn_91_3FF4(void*, short);

void* fn_91_4110(void* object, short deleting) {
    if (object != 0) {
        fn_91_4060(static_cast<unsigned char*>(object) + 0x24, static_cast<short>(-1));
        fn_91_3FF4(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
