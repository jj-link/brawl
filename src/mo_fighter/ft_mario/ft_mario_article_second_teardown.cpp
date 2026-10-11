extern "C" {
void* fn_27_1D81C8(void*, short);
void* fn_91_16080(void*, short);
void* fn_91_60C8(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_91_6164(void*, short);
void* fn_91_72EC(void*, short);
void* fn_91_622C(void*, short);
void* fn_91_62C8(void*, short);
void* fn_91_61D0(void*, short);
void* fn_27_C7770(void*, short);
void* fn_91_15DDC(void*, short);
void* fn_91_15E4C(void*, short);
void* fn_91_15EDC(void*, short);
void* fn_91_15F68(void*, short);
void* fn_91_15FF4(void*, short);

#pragma dont_inline on
void* fn_91_15D54(void* object, short deleting) {
    if (object != 0) {
        fn_91_60C8(static_cast<unsigned char*>(object) + 0x1dc0, static_cast<short>(-1));
        fn_27_1DBB60(static_cast<unsigned char*>(object) + 0x1d88, static_cast<short>(-1));
        fn_91_15DDC(static_cast<unsigned char*>(object) + 0xcc, static_cast<short>(-1));
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_15DDC(void* object, short deleting) {
    if (object != 0) {
        fn_91_15E4C(static_cast<unsigned char*>(object) + 0x170c, static_cast<short>(-1));
        fn_91_16080(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_15E4C(void* object, short deleting) {
    if (object != 0) {
        fn_91_6164(static_cast<unsigned char*>(object) + 0x4b0, static_cast<short>(-1));
        fn_91_15EDC(static_cast<unsigned char*>(object) + 0x384, static_cast<short>(-1));
        fn_91_15F68(static_cast<unsigned char*>(object) + 0x258, static_cast<short>(-1));
        fn_91_15FF4(static_cast<unsigned char*>(object) + 0x12c, static_cast<short>(-1));
        fn_91_72EC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_15EDC(void* object, short deleting) {
    if (object != 0) {
        fn_91_622C(static_cast<unsigned char*>(object) + 0xdc, static_cast<short>(-1));
        fn_91_62C8(static_cast<unsigned char*>(object) + 0xc0, static_cast<short>(-1));
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        if (object != 0) fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_15F68(void* object, short deleting) {
    if (object != 0) {
        fn_91_622C(static_cast<unsigned char*>(object) + 0xdc, static_cast<short>(-1));
        fn_91_62C8(static_cast<unsigned char*>(object) + 0xc0, static_cast<short>(-1));
        fn_91_61D0(static_cast<unsigned char*>(object) + 0x14, static_cast<short>(-1));
        if (object != 0) fn_27_C7770(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_15FF4(void* object, short deleting) {
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
