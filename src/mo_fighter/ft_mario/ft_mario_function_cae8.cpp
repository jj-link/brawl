#pragma force_active on
extern "C" {
void* fn_91_CA88(void*, short);
void* fn_91_C954(void*, short);

#pragma dont_inline on
void* fn_91_CAE8(void* object, short deleting) {
    if (object != 0) {
        fn_91_CA88(static_cast<unsigned char*>(object) + 0x204, static_cast<short>(-1));
        if (object != 0) fn_91_C954(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
