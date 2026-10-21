#pragma force_active on
extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_91_644C(void*, short);
void* fn_91_8140(void*, short);
void* fn_27_CBF58(void*, short);

#pragma dont_inline on
void* fn_91_819C(void* object, short deleting) {
    if (object != 0) {
        fn_27_97968(static_cast<unsigned char*>(object) + 0x6c, static_cast<short>(-1));
        fn_27_1CCCC(static_cast<unsigned char*>(object) + 0x5c, static_cast<short>(-1));
        fn_91_644C(static_cast<unsigned char*>(object) + 0x50, static_cast<short>(-1));
        fn_91_8140(static_cast<unsigned char*>(object) + 0x38, static_cast<short>(-1));
        if (object != 0) fn_27_CBF58(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
