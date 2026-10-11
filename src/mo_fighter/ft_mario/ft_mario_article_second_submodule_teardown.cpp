extern "C" {
void* fn_27_C31CC(void*, short);
void* fn_91_46A8(void*, short);
void* fn_91_4564(void*, short);
void* fn_91_4504(void*, short);
void* fn_91_76F8(void*, short);
void* fn_91_6984(void*, short);
void* fn_27_C74E8(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CA80(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_19A33C(void*, short);
void* fn_91_6088(void*, short);

void* fn_91_1620C(void* object, short deleting) {
    if (object != 0) {
        fn_27_C31CC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_16268(void* object, short deleting) {
    if (object != 0) {
        fn_91_46A8(static_cast<unsigned char*>(object) + 0x24, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_162C8(void* object, short deleting) {
    if (object != 0) {
        fn_91_4564(static_cast<unsigned char*>(object) + 0xc4, static_cast<short>(-1));
        fn_91_4504(static_cast<unsigned char*>(object) + 0xb0, static_cast<short>(-1));
        fn_91_76F8(static_cast<unsigned char*>(object) + 0x98, static_cast<short>(-1));
        fn_91_6984(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        fn_27_C74E8(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_16358(void* object, short deleting) {
    if (object != 0) {
        __dt__27soCollisionAttackModuleImplFv(static_cast<unsigned char*>(object) + 0x124, static_cast<short>(-1));
        fn_27_82AD4(static_cast<unsigned char*>(object) + 0x120, static_cast<short>(-1));
        fn_27_4CAA0(static_cast<unsigned char*>(object) + 0x9c, static_cast<short>(-1));
        fn_27_19CA80(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_163DC(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90(static_cast<unsigned char*>(object) + 0x1c, static_cast<short>(-1));
        fn_27_21038(static_cast<unsigned char*>(object) + 0x8, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_16448(void* object, short deleting) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(object) + 0x44, static_cast<short>(-1));
        fn_27_19A33C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_164B4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) fn_91_6088(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_16514(void* object, short deleting) {
    if (object != 0) {
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
