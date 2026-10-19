#pragma force_active on
extern "C" {
void* fn_27_10424(void*, short);
void* fn_27_19A97C(void*, short);

#pragma dont_inline on
void* fn_91_8420(void* object, short deleting) {
    if (object != 0) {
        fn_27_10424(static_cast<unsigned char*>(object) + 0x7C, static_cast<short>(-1));
        if (object != 0) fn_27_19A97C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
