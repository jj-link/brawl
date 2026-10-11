extern "C" {
void* fn_91_4564(void*, short);
void* fn_91_4504(void*, short);
void* fn_91_18BBC(void*, short);
void* fn_91_65A4(void*, short);
void* fn_91_662C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_27_1A2D10(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CCC8(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_91_6984(void*, short);
void* fn_91_6088(void*, short);

#pragma dont_inline on
void* fn_91_18B20(void* object, short deleting) {
    if (object != 0) {
        fn_91_4564(static_cast<unsigned char*>(object) + 0x110, static_cast<short>(-1));
        fn_91_4504(static_cast<unsigned char*>(object) + 0xfc, static_cast<short>(-1));
        fn_91_18BBC(static_cast<unsigned char*>(object) + 0xec, static_cast<short>(-1));
        fn_91_65A4(static_cast<unsigned char*>(object) + 0x48, static_cast<short>(-1));
        fn_91_662C(static_cast<unsigned char*>(object) + 0x10, static_cast<short>(-1));
        fn_27_C74E8(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_18BBC(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2D10(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_18C18(void* object, short deleting) {
    if (object != 0) {
        __dt__27soCollisionAttackModuleImplFv(static_cast<unsigned char*>(object) + 0x1b4, static_cast<short>(-1));
        fn_27_82AD4(static_cast<unsigned char*>(object) + 0x1b0, static_cast<short>(-1));
        fn_27_4CAA0(static_cast<unsigned char*>(object) + 0x12c, static_cast<short>(-1));
        fn_27_19CCC8(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_18C9C(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90(static_cast<unsigned char*>(object) + 0x9c, static_cast<short>(-1));
        fn_27_21038(static_cast<unsigned char*>(object) + 0x88, static_cast<short>(-1));
        fn_91_6984(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_18D14(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) fn_91_6088(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
