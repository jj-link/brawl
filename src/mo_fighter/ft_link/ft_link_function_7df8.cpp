#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_93_7D9C(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);

#pragma dont_inline on
void* fn_93_7DF8(void* object, short deleting) {
    if (object != 0) {
        fn_27_93100(static_cast<unsigned char*>(object) + 0x11c6c, static_cast<short>(-1));
        fn_93_7D9C(static_cast<unsigned char*>(object) + 0x7c, static_cast<short>(-1));
        fn_27_19F4C4(static_cast<unsigned char*>(object) + 0x20, static_cast<short>(-1));
        fn_27_1A55B0(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
