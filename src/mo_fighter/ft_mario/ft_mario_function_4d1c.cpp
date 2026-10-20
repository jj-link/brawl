#pragma force_active on
extern "C" {
void* fn_27_1A1FE4(void*, short);
void* fn_91_4CA4(void*, short);

#pragma dont_inline on
void* fn_91_4D1C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1FE4(static_cast<unsigned char*>(object) + 0x244, static_cast<short>(-1));
        if (object != 0) fn_91_4CA4(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
