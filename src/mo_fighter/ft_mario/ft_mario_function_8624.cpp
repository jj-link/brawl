#pragma force_active on
extern "C" {
void* fn_27_B81C4(void*, short);
void* fn_91_85C8(void*, short);
void* fn_27_198034(void*, short);

#pragma dont_inline on
void* fn_91_8624(void* object, short deleting) {
    if (object != 0) {
        fn_27_B81C4(static_cast<unsigned char*>(object) + 0xa4, static_cast<short>(-1));
        fn_91_85C8(static_cast<unsigned char*>(object) + 0x48, static_cast<short>(-1));
        if (object != 0) fn_27_198034(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
