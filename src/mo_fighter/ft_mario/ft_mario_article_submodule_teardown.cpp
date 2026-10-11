extern "C" {
void* fn_91_7378(void*, short);
void* fn_91_4564(void*, short);
void* fn_91_4504(void*, short);
void* fn_91_76F8(void*, short);
void* fn_91_65A4(void*, short);
void* fn_91_662C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_91_12F64(void*, short);
void* __dt__22soControllerModuleImplFv(void*, short);
void* fn_27_252D0(void*, short);
void* fn_27_19FFEC(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_91_2BC8(void*, short);
void* fn_91_6984(void*, short);
void* fn_91_6088(void*, short);

#pragma dont_inline on
void* fn_91_12E08(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12E68(void* object, short deleting) {
    if (object != 0) {
        fn_91_4564(static_cast<unsigned char*>(object) + 0x118, static_cast<short>(-1));
        fn_91_4504(static_cast<unsigned char*>(object) + 0x104, static_cast<short>(-1));
        fn_91_76F8(static_cast<unsigned char*>(object) + 0xec, static_cast<short>(-1));
        fn_91_65A4(static_cast<unsigned char*>(object) + 0x48, static_cast<short>(-1));
        fn_91_662C(static_cast<unsigned char*>(object) + 0x10, static_cast<short>(-1));
        fn_27_C74E8(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12F04(void* object, short deleting) {
    if (object != 0) {
        fn_91_12F64(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12F64(void* object, short deleting) {
    if (object != 0) {
        __dt__22soControllerModuleImplFv(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12FC0(void* object, short deleting) {
    if (object != 0) {
        fn_27_252D0(static_cast<unsigned char*>(object) + 0x3c, static_cast<short>(-1));
        if (object != 0) fn_27_19FFEC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_13034(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90(static_cast<unsigned char*>(object) + 0xd8, static_cast<short>(-1));
        fn_27_21038(static_cast<unsigned char*>(object) + 0xc4, static_cast<short>(-1));
        fn_91_2BC8(static_cast<unsigned char*>(object) + 0x88, static_cast<short>(-1));
        fn_91_6984(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_130B8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) fn_91_6088(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
