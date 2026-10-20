#pragma force_active on
extern "C" {
void* fn_91_C5C8(void*, short);
void* fn_91_C494(void*, short);

#pragma dont_inline on
void* fn_91_C628(void* object, short deleting) {
    if (object != 0) {
        fn_91_C5C8(static_cast<unsigned char*>(object) + 0x134, static_cast<short>(-1));
        if (object != 0) fn_91_C494(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
