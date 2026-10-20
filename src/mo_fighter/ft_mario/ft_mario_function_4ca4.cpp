#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void*, short);
void* fn_91_4C2C(void*, short);

#pragma dont_inline on
void* fn_91_4CA4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x218, static_cast<short>(-1));
        if (object != 0) fn_91_4C2C(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
