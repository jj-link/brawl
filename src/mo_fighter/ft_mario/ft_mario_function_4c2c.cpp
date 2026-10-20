#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void* fn_91_4BB4(void*, short);

#pragma dont_inline on
void* fn_91_4C2C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x1fc, static_cast<short>(-1));
        if (object != 0) fn_91_4BB4(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
