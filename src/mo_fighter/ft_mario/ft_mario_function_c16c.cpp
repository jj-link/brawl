#pragma force_active on
extern "C" {
void* fn_91_C10C(void*, short);
void* fn_91_BFEC(void*, short);

#pragma dont_inline on
void* fn_91_C16C(void* object, short deleting) {
    if (object != 0) {
        fn_91_C10C(static_cast<unsigned char*>(object) + 0x60, static_cast<short>(-1));
        fn_91_BFEC(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
