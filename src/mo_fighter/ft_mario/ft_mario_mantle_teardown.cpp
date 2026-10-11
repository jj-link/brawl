extern "C" {
void* fn_91_FA44(void*, short);
void* fn_91_FAA0(void*, short);
void* fn_27_1D81C8(void*, short);
void* fn_91_F9D4(void* object, short deleting) {
    if (object != 0) {
        fn_91_FA44(static_cast<unsigned char*>(object) + 0xcc, static_cast<short>(-1));
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline on
void* fn_91_FA44(void* object, short deleting) {
    if (object != 0) {
        fn_91_FAA0(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
