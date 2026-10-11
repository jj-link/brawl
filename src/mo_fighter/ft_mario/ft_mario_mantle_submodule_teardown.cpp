extern "C" {
void* fn_91_21B8(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_91_6984(void*, short);
void* fn_91_2818(void*, short);
void* fn_91_FDC4(void*, short);
void* fn_91_FBD8(void* object, short deleting) {
    if (object != 0) {
        fn_91_21B8(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_FC34(void* object, short deleting) {
    if (object != 0) {
        fn_27_252D0(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_FC94(void* object, short deleting) {
    if (object != 0) {
        const short destroyMember = -1;
        fn_27_13C90(static_cast<unsigned char*>(object) + 0x9c, destroyMember);
        fn_27_21038(static_cast<unsigned char*>(object) + 0x88, destroyMember);
        fn_91_6984(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_FD0C(void* object, short deleting) {
    if (object != 0) {
        fn_91_2818(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_FD68(void* object, short deleting) {
    if (object != 0) {
        fn_91_FDC4(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline on
void* fn_91_FDC4(void* object, short deleting) {
    if (object != 0 && deleting > 0) operator delete(object);
    return object;
}
#pragma dont_inline reset
}
