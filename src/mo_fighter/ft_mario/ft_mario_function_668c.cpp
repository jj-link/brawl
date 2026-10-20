#pragma force_active on
extern "C" {
void* fn_27_1A262C(void*, short);
void* fn_91_40D0(void*, short);
void* fn_91_3FF4(void*, short);

#pragma dont_inline on
void* fn_91_668C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        if (p + 0x24 != 0) {
            fn_27_1A262C(p + 0x34, static_cast<short>(-1));
            fn_91_40D0(p + 0x24, static_cast<short>(0));
        }
        fn_91_3FF4(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
