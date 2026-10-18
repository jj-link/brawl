#pragma force_active on
extern "C" {
void* fn_91_7B18(void*, short);
void* fn_91_7814(void*, short);

#pragma dont_inline on
void* fn_91_7B84(void* object, short deleting) {
    if (object != 0) {
        fn_91_7B18(static_cast<unsigned char*>(object) + 0x1AA00, static_cast<short>(-1));
        if (object != 0) fn_91_7814(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
