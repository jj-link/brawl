#pragma force_active on
extern "C" {
void* fn_27_B21D0(void*, short);
void* fn_27_CB4A0(void*, short);

#pragma dont_inline on
void* fn_91_3F3C(void* object, short deleting) {
    if (object != 0) {
        fn_27_B21D0(static_cast<unsigned char*>(object) + 0x50, static_cast<short>(-1));
        if (object != 0) fn_27_CB4A0(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
