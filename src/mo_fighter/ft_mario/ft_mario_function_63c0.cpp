#pragma force_active on
extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_91_644C(void*, short);
void* fn_27_CBF58(void*, short);

#pragma dont_inline on
void* fn_91_63C0(void* object, short deleting) {
    if (object != 0) {
        fn_27_97968(static_cast<unsigned char*>(object) + 0x58, static_cast<short>(-1));
        fn_27_1CCCC(static_cast<unsigned char*>(object) + 0x48, static_cast<short>(-1));
        fn_91_644C(static_cast<unsigned char*>(object) + 0x3c, static_cast<short>(-1));
        if (object != 0) fn_27_CBF58(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
