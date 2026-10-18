#pragma force_active on
extern "C" {
void fn_27_57BA0(void*, short);
void* fn_91_19B8(void*, short);
void* fn_91_1A14(void*, short);

void* fn_91_1938(void* object, short deleting) {
    if (object != 0) {
        if (static_cast<unsigned char*>(object) + 0x20 != 0) fn_27_57BA0(static_cast<unsigned char*>(object) + 0x20, static_cast<short>(0));
        fn_91_19B8(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(0));
        fn_91_1A14(static_cast<unsigned char*>(object) + 8, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
