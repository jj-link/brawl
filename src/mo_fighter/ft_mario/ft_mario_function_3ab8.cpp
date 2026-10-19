#pragma force_active on
extern "C" {
void* fn_27_689B0(void*, short);
void* fn_27_1985B4(void*, short);

#pragma dont_inline on
void* fn_91_3AB8(void* object, short deleting) {
    if (object != 0) {
        fn_27_689B0(static_cast<unsigned char*>(object) + 0x7c, static_cast<short>(-1));
        if (object != 0) fn_27_1985B4(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
