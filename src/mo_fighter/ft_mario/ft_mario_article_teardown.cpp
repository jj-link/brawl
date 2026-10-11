extern "C" {
void* fn_27_1D81C8(void*, short);
void* fn_91_12168(void*, short);
void* fn_91_6164(void*, short);
void* fn_91_72EC(void*, short);
void* fn_91_622C(void*, short);
void* fn_91_62C8(void*, short);
void* fn_91_61D0(void*, short);
void* fn_27_C7770(void*, short);
void* fn_91_11EC0(void*, short);
void* fn_91_11F34(void*, short);
void* fn_91_11FC4(void*, short);
void* fn_91_12050(void*, short);
void* fn_91_120DC(void*, short);

#pragma dont_inline on
void* fn_91_11E50(void* object, short deleting) {
    if (object != 0) {
        fn_91_11EC0(static_cast<unsigned char*>(object) + 0xcc, static_cast<short>(-1));
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_11EC0(void* object, short deleting) {
    if (object != 0) {
        fn_91_11F34(static_cast<unsigned char*>(object) + 0x18368, static_cast<short>(-1));
        fn_91_12168(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_11F34(void* object, short deleting) {
    if (object != 0) {
        fn_91_6164(static_cast<unsigned char*>(object) + 0x4b0, static_cast<short>(-1));
        fn_91_11FC4(static_cast<unsigned char*>(object) + 0x384, static_cast<short>(-1));
        fn_91_12050(static_cast<unsigned char*>(object) + 0x258, static_cast<short>(-1));
        fn_91_120DC(static_cast<unsigned char*>(object) + 0x12c, static_cast<short>(-1));
        fn_91_72EC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_11FC4(void* object, short deleting) {
    if (object != 0) {
        fn_91_622C(static_cast<unsigned char*>(object) + 0xdc, static_cast<short>(-1));
        fn_91_62C8(static_cast<unsigned char*>(object) + 0xc0, static_cast<short>(-1));
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        if (object != 0) fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12050(void* object, short deleting) {
    if (object != 0) {
        fn_91_622C(static_cast<unsigned char*>(object) + 0xdc, static_cast<short>(-1));
        fn_91_62C8(static_cast<unsigned char*>(object) + 0xc0, static_cast<short>(-1));
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        if (object != 0) fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_120DC(void* object, short deleting) {
    if (object != 0) {
        fn_91_622C(static_cast<unsigned char*>(object) + 0xdc, static_cast<short>(-1));
        fn_91_62C8(static_cast<unsigned char*>(object) + 0xc0, static_cast<short>(-1));
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        if (object != 0) fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
