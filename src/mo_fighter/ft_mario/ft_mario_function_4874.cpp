#pragma force_active on
extern "C" {
void* fn_27_1A1E70(void*, short);
void* fn_91_4814(void*, short);

#pragma dont_inline on
void* fn_91_4874(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x1c, static_cast<short>(-1));
        fn_91_4814(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
