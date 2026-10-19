#pragma force_active on
extern "C" {
void* fn_91_77B4(void*, short);
void* fn_91_6D7C(void*, short);

#pragma dont_inline on
void* fn_91_7814(void* object, short deleting) {
    if (object != 0) {
        fn_91_77B4(static_cast<unsigned char*>(object) + 0x1fcc, static_cast<short>(-1));
        fn_91_6D7C(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
