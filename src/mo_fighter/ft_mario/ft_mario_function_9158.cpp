#pragma force_active on
extern "C" {
void* fn_91_622C(void*, short);
void* fn_91_62C8(void*, short);
void* fn_91_61D0(void*, short);
void* fn_27_C7770(void*, short);

#pragma dont_inline on
void* fn_91_9158(void* object, short deleting) {
    if (object != 0) {
        fn_91_622C(static_cast<unsigned char*>(object) + 0xdc, static_cast<short>(-1));
        fn_91_62C8(static_cast<unsigned char*>(object) + 0xc0, static_cast<short>(-1));
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        if (object != 0) fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
