#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void* fn_91_4A4C(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_4AC4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x138, static_cast<short>(-1));
        if (object != 0) {
            fn_91_4A4C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
#pragma dont_inline reset
}
