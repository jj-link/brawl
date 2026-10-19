#pragma force_active on
extern "C" {
void fn_27_1A2524(void*, short);
void* fn_91_40D0(void*, short);

#pragma dont_inline on
void* fn_91_4060(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, static_cast<short>(-1));
        fn_91_40D0(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
