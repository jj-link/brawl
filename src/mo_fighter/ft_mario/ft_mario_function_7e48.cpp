#pragma force_active on
extern "C" {
void* fn_91_7DE8(void*, short);
void* fn_91_7B84(void*, short);

#pragma dont_inline on
void* fn_91_7E48(void* object, short deleting) {
    if (object != 0) {
        fn_91_7DE8(static_cast<unsigned char*>(object) + 0x24680, static_cast<short>(-1));
        if (object != 0) fn_91_7B84(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
